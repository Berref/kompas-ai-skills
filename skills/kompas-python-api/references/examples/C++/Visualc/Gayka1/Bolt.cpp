////////////////////////////////////////////////////////////////////////////////
//
//  Boltmain.cpp
//  Файл описывает класс BoltMain - класс болта ГОСТ 7787-81, и наследуемые от
//  него классы Bolt7786 (болты ГОСТ 7786-81 и ГОСТ 17673-81), Bolt7802 (ГОСТ 7802-81),
//  Вolt7801 (ГОСТ 7781-81), Bolt7783 (ГОСТ 7783-81), Bolt7785 (ГОСТ 7785-81)
//
//  BoltMainStruct - Основная структура данных болта
//  BoltMain       - Болт ГОСТ 7787-81, Базовый класс для остальных болтов
//  Внеклассные функции
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "Bolt.h"
#include <Libhppar.h>
#include "math.h"
#include <SafeArrayUtils.h>
#include "CPar.h"

extern HINSTANCE g_hInstance;
//reference posLeater=0;
extern ksAPI7::IApplicationPtr newKompasAPI; // Интерфейс Приложения Компас 
#define IDS_DB7787              "7787.loa"



#define STR_DB_READ_ALL         ""
#define STR_DB_READ_1_2         "1 2"
#define STR_DB_READ_1_2_12      "1 2 12"
#define STR_DB_READ_2_2         "2 2"

#define IDS_D_LB_CONDITION      "L>=%.0f && dr=%.0f"
#define IDS_L_DRCONDITION       "L=%.0f && dr=%.0f"
#define READBYDIAM              "dr = %g"

// Строки для работы с БД
#define IDS_DBCOLUMN_DR         "dr"
#define IDS_DBCOLUMN_L          "L"
#define IDS_DBCOLUMN_ALL        ""
#define IDS_DBCOLUMN_Z4         "z4"
#define IDS_DBCOLUMN_DP         "dp"



//------------------------------------------------------------------------------
// Конструктор
// ---
BoltMainStruct::BoltMainStruct( ushort _gost ) 
{
  gost = _gost; // ГОСТ
  Init();
}


//------------------------------------------------------------------------------
// Конструктор копий
// ---
BoltMainStruct::BoltMainStruct( const BoltMainStruct & boltSt ) 
{
  *this = boltSt;
}


//------------------------------------------------------------------------------
// Оператор =.
// ---
const BoltMainStruct & BoltMainStruct::operator = ( const BoltMainStruct & boltSt ) 
{
  l      = boltSt.l;                         // длина стержня
  dr     = boltSt.dr;                        // Диаметр резьбы
  b      = boltSt.b;                         // Длина резьбы
  m      = boltSt.m;                         // масса 1000 болтов
  d      = boltSt.d;                         // диаметр головки
  k      = boltSt.k;                         // высота головки
  kr     = boltSt.kr;                        // резьба на b
  param1 = boltSt.param1;                    // размер стороны подголовка или высота уса
  param2 = boltSt.param2;                    // радиус сферы или угол alpha
  v      = boltSt.v;                         // ширина уса или высота подголовка для ГОСТ 7802
  h      = boltSt.h;                         // высота подголовка ГОСТ 7783
  d1     = boltSt.d1;                        // диаметр подголовка ГОСТ 7783
  p      = boltSt.p;                         // Шаг резьбы
  dp     = boltSt.dp;                        // Диаметр конца
  rp     = boltSt.rp;                        // радиус под головкой
  z4     = boltSt.z4;                        // величина фаски
  f      = boltSt.f;                         // Битовые маски
  gost   = boltSt.gost;                      // ГОСТ
  perf   = boltSt.perf;                      // исполнение

  return *this;
}


//-------------------------------------------------------------------------------
//
// ---
void BoltMainStruct::Init()
{
  l      = 90;                        // длина стержня
  dr     = 10;                        // Диаметр резьбы
  p      = 1.5;                       // Шаг резьбы
  kr     = 1;                         // резьба на b
  dp     = 7;                         // Диаметр конца
  z4     = 1.5;                       // величина фаски
  f      = 0;                         // Битовые маски
  rp     = (float)(0.4);              // радиус под головкой
  b      = 26;                        // Длина резьбы
  param1 = 0;                         //
  param2 = 0;                         //
  v      = 0;                         //
  h      = 0;                         //
  d1     = 0;                         //
  b1     = 0;                         //
  perf   = 1;                         // исполнение

  switch ( gost )
  {
    case 7786  :
    {
      m      = (float)(48.26);        // масса 1000 болтов
      d      = 18;                    // диаметр головки
      k      = 8;                     // высота головки
      param1 = 10;                    // размер стороны подголовка
      break;
    }

    case 7783  :
    {
      m      = (float)(53.80);        // масса 1000 болтов
      d      = 20;                    // диаметр головки
      k      = 7;                     // высота головки
      param1 = (float)(2.7);          // высота уса
      param2 = (float)(10.5);         // радиус сферы
      v      = (float)(3.2);          // ширина уса
      h      = 5;                     // высота подголовка
      d1     = 10;                    // диаметр подголовка или стержня
      break;
    }

    case 7785  :
    {
      m      = (float)(49.45);        // масса 1000 болтов
      d      = 20;                    // диаметр головки
      k      = 5.5;                   // высота головки
      param1 = 4,2;                   // высота уса
      param2 = 90;                    // угол alpha
      v      = (float)(3.2);          // ширина уса
      break;
    }

    case 17673 :
    {
      m      = (float)(55.98);        // масса 1000 болтов
      d      = 23;                    // диаметр головки
      k      = 11;                    // высота головки
      param1 = 10;                    // размер стороны подголовка
      break;
    }

    case 7801 :
    {
      m      = (float)(54.30);        // масса 1000 болтов
      d      = 23;                    // диаметр головки
      k      = 5;                     // высота головки
      param1 = 5;                     // высота уса
      param2 = 18;                    // радиус сферы
      break;
    }

    case 7802 :
    {
      m      = 55,53;                 // масса 1000 болтов
      d      = 23;                    // диаметр головки
      k      = 5,0;                   // высота головки
      param1 = 10;                    // размер стороны подголовка
      param2 = 18;                    // радиус сферы
      v      = 6;                     // высота подголовка
      break;
    }

    default  :
    {
      m = (float)(50.04);             // масса 1000 болтов
      d = 17;                         // диаметр головки
      k = 10.5;                       // высота головки
      break;
    }
  }
}


////////////////////////////////////////////////////////////////////////////////
//
// Внеклассные функции
//
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
// возвращает идентификатор БД в соответствии с указанным ГОСТом
// ---
LPTSTR GetNameDB( int gost ) 
{
// RA  switch ( gost )               // определить идентификатор
// RA  {
// RA    case 7783  : return IDS_DB7783;
// RA    case 7785  : return IDS_DB7785;
// RA    case 7786  : return IDS_DB7786;
// RA    case 7801  : return IDS_DB7801;
// RA    case 7802  : return IDS_BD_1;
// RA    case 17673 : return IDS_DB17673;
// RA    default    : return IDS_DB7787;
// RA  }
  return LPTSTR( IDS_DB7787 );
}


//------------------------------------------------------------------------------
// точка пересечения фаски и линии обозначения резьбы
// ---
void IntersectFaceThread( const BoltMainStruct & bolt,
                          int & kp, double & xp, double & yp ) 
{
  float pThread = (float)(bolt.dr * 0.5 - MODSTEP_REAL * bolt.p); // координата у линии обозначения резьбы
  float endThr  = (float)(bolt.l - bolt.b);                       // координата конца резьбы
  ::IntersectLinSLinS( bolt.l - bolt.z4, bolt.dr * 0.5, bolt.l, bolt.dp * 0.5,
                       endThr,           pThread,       bolt.l, pThread,
                       &kp, &xp, &yp );
}


//------------------------------------------------------------------------------
// Рисует половинку стержня для болтов ГОСТ 7786, 7802 и 7787.
// ---
void BoltBarDraw( const BoltMainStruct & bolt, const int sign, bool apl = false ) 
{
  float radThr    = (float)(sign * bolt.dr * 0.5);                // радиус резьбы
  float lengthBar = (float)(bolt.l - bolt.z4);                    // длина стержня без фаски
  float headRest  = (float)(bolt.gost == 7802 ? bolt.v : bolt.k); // высота подголовка
  float radDp     = (float)(sign * bolt.dp * 0.5);                // радиус резьбы без фаски

  ::LineSeg( lengthBar, radThr, bolt.l,    radDp,  BASE_LINE );      // фаска
  ::LineSeg( bolt.l,    radDp,  bolt.l,    0,      BASE_LINE );      // конец болта
  ::LineSeg( headRest,  radThr, lengthBar, radThr, BASE_LINE );      // стержень без фаски

  if ( !apl )
  {
    ::LineSeg( lengthBar, radThr, lengthBar, 0, BASE_LINE );         // конец стержня без фаски

    float endThr = bolt.l - bolt.b;                                  // координата конца резьбы
    if ( bolt.kr )
      ::LineSeg( endThr, radThr, endThr, 0, BASE_LINE );             // граница резьбы

    float  pThread = (float)(radThr - sign * MODSTEP_REAL * bolt.p); // координата у линии обозначения резьбы
    int    kp = 0;
    double xp = 0.0, yp = 0.0;
    ::IntersectFaceThread( bolt, kp, xp, yp );

    if ( kp )
      ::LineSeg( endThr, pThread, xp, pThread, SLIM_LINE );          // обозначение резьбы
  }
}


//------------------------------------------------------------------------------
// пересечение грани подголовка и фаски для болтов ГОСТ 7786, 7802.
// ---
void IntersectHeadRestFaset( const BoltMainStruct & bolt,
                             int & kp1, double & xp1, double & yp1 ) 
{
  float headRest  = bolt.gost == 7802 ? bolt.v : bolt.k;    // высота подголовка
  float radThr    = (float)(bolt.dr * 0.5);                 // радиус резьбы
  float sideHead  = (float)(bolt.param1 * ::sqrt( 0.5 ));   // сторона подголовка

  ::IntersectLinLin( headRest/*коор-та x*/, radThr/*коор-та у*/,   120/*угол*/, // первая линия
                     0/*коор-та x*/,        sideHead/*коор-та у*/, 0/*угол*/,   // вторая линия
                     &kp1, &xp1, &yp1 );                                        // возвращяемые значения
}


//------------------------------------------------------------------------------
// Рисует границу стержня, фаску и обзначение резьбы для болтов ГОСТ 7801 и 7783.
// ---
void BoltBarThrDraw( const BoltMainStruct & bolt ) 
{
  float lengthBar = bolt.l - bolt.z4;                                // длина стержня без фаски
  float radThr    = (float)(bolt.dr * 0.5);                          // радиус резьбы
  float mRadThr   = - radThr;

  ::LineSeg( lengthBar,  radThr,  lengthBar,  mRadThr, BASE_LINE );  // конец стержня без фаски

  float endThr = bolt.l - bolt.b;                                    // координата конца резьбы
  ::LineSeg( endThr, radThr, endThr, mRadThr, BASE_LINE );           // граница резьбы

  float radDp = (float)(bolt.dp * 0.5);                              // радиус резьбы без фаски
  ::LineSeg( lengthBar, radThr,  bolt.l, radDp, BASE_LINE );         // фаска вверху

  float mRadDp = - radDp;
  ::LineSeg( bolt.l,    radDp,   bolt.l, mRadDp, BASE_LINE );        // конец болта
  ::LineSeg( lengthBar, mRadThr, bolt.l, mRadDp, BASE_LINE );        // фаска внизу

  float pThread = (float)(radThr - MODSTEP_REAL * bolt.p);           // координата у линии обозначения резьбы
  int kp;
  double xp, yp;
  ::IntersectFaceThread( bolt, kp, xp, yp );

  if ( kp ) 
  {
    ::LineSeg( endThr, pThread,   xp, pThread,   SLIM_LINE );      // обозначение резьбы вверху
    ::LineSeg( endThr, - pThread, xp, - pThread, SLIM_LINE );      // обозначение резьбы внизу
  }
}


//------------------------------------------------------------------------------
// Рисует оси в основном виде для болтов ГОСТ 7801 и 7783.
// ---
void BoltAxisDraw( const BoltMainStruct & bolt ) 
{
  if ( !(bolt.f & AXIS_OFF) )         // оси
    ::LineSeg( - bolt.k - AXIS_END, 0, (bolt.f & DRAW_ST_OF)
                                        ? AXIS_END
                                        : bolt.l + AXIS_END, 0, AXIS_LINE );
}


//------------------------------------------------------------------------------
// Рисует стержень в виде снизу.
// ---
void BoltBarBottomDraw( const BoltMainStruct & bolt ) 
{
  // тело стержня
  float radiusThread = (float)(bolt.dr * 0.5);
  ::Circle( 0/*x центра*/, 0/*y центра*/, radiusThread/*радиус*/, BASE_LINE );

  // обозначение резьбы (тонкой линией)
  float stepThd = (float)(radiusThread - MODSTEP_REAL * bolt.p);
  ::ArcByPoint( 0/*x центра*/,             0/*y центра*/,           stepThd/*радиус*/,
                bolt.p/*x нач. точки*/,    stepThd/*y нач. точки*/,
                - stepThd/*x кон. точки*/, bolt.p/*y кон. точки*/,
                -1/*направление*/,         SLIM_LINE );
}


//------------------------------------------------------------------------------
// Конструктор. Тело конструктора выполняется только для болта ГОСТ 7787-81
// для остальных болтов конструктор пуст
// ---
BoltMain::BoltMain( ushort gost )
  : CPar( CM_BOLT7787 )
  , bolt      ( gost )
{
  ::memset( &bBase.bg, 0, sizeof(BoltMainBase) );
  if ( bolt.gost == 7787 )
    InitBolt();
}


//------------------------------------------------------------------------------
// конструктор копий
// ---
BoltMain::BoltMain( const BoltMain & other ) 
  : CPar( CM_BOLT7787 )
{
  ::memset( &bBase.bg, 0, sizeof(BoltMainBase) );
  Assign( other );
}


//-------------------------------------------------------------------------------
// Конструктор
// ---
BoltMain::BoltMain( reference ref, bool fromDataBase )
  : CPar( CM_BOLT7787, ref, fromDataBase )
  , bolt( 7787 )
{
  if ( fromDataBase || !GetMacroParam(ref, *this, Size()) )
  {
    InitBolt();
  }
  else
  {
    if ( !m_baseParam.version )
    {
      m_baseParam.version = 1;
    }
  }
}


//------------------------------------------------------------------------------
// Деструктор
// ---
BoltMain::~BoltMain() 
{
  CloseBase();
}


//------------------------------------------------------------------------------
// Инициализация параметров болта
// ---
void BoltMain::InitBolt()
{
  m_baseParam.drawType = ID_VIEW; // Тип отображения
  angle                = 0;       // Угол
}


//------------------------------------------------------------------------------
// конструктор копии
// ---
CPar & BoltMain::DublicateObj()
{
  return *new BoltMain( *this );
}


//------------------------------------------------------------------------------
//
// ---
void BoltMain::Assign( const BoltMain & other )
{
  CPar::Assign( other );
  bolt = other.bolt;
}


//-------------------------------------------------------------------------------
// закрыть БД
// ---
void BoltMain::CloseBase()
{
  if ( bBase.bg )
    ::DeleteDB( bBase.bg );          // Удалить базу

  if ( bBase.bs )
    ::DeleteDB( bBase.bs );
}


//------------------------------------------------------------------------------
// открытие БД и создание отношений
// ---
bool BoltMain::OpenBase()
{
  bool okey = false;
  bBase.bg  = ::CreateDBT( _T("TXT_DB") );                      // "TXT_DB" - Создаём базы данных
  bBase.bs  = ::CreateDBT( _T("TXT_DB") );
  // формируем строку с именем первого файла БД
  if ( ::_ConnectDB(bBase.bg, _T("7787.loa")/*::GetNameDB(bolt.gost)*/) )  // Связь с базой данных
  {
    if ( ::_ConnectDB(bBase.bs, _T("R_SH_K.loa")) )      // Связь с базой данных R_sh_k.loa
    {
      // Отношение для получения из базы диаметров резьбы
      bBase.rs1 = ::Relation( bBase.bg );             
        ::RChar( IDS_DBCOLUMN_DR, LENGTH_STR/*длина строки*/, 0/*тип колонки(ODBC)*/ );
        ::RFloatT( _T(IDS_DBCOLUMN_DR) );
      ::EndRelation();

      if ( ::DoStatementT(bBase.bg, bBase.rs1, _T(STR_DB_READ_2_2)) )  // "2 2"
      {
        bBase.rs2 = ::Relation( bBase.bg );            // Отношение для получения из базы длин
          ::RChar ( IDS_DBCOLUMN_L, LENGTH_STR, 0 );
          ::RFloatT( _T(IDS_DBCOLUMN_DR) );
        ::EndRelation();

        if ( ::DoStatementT(bBase.bg, bBase.rs2, _T(STR_DB_READ_1_2)) ) // "1 2"
        {
          bBase.rs3 = ::Relation( bBase.bg );           // Отношение для получения всех данных из базы
            ::RFloatT( _T(IDS_DBCOLUMN_L)   );
            ::RFloatT( _T(IDS_DBCOLUMN_DR)  );
            ::RFloatT( _T(IDS_DBCOLUMN_ALL) );
            ::RFloatT( _T(IDS_DBCOLUMN_ALL) );

            if ( bolt.gost != 7787 ) 
            {
              ::RFloatT( _T(IDS_DBCOLUMN_ALL) );
              ::RFloatT( _T(IDS_DBCOLUMN_ALL) );
              ::RIntT  ( _T(IDS_DBCOLUMN_ALL) );
              ::RFloatT( _T(IDS_DBCOLUMN_ALL) );
              ::RFloatT( _T(IDS_DBCOLUMN_ALL) );
              ::RFloatT( _T(IDS_DBCOLUMN_ALL) );

              if ( (bolt.gost != 7786) || (bolt.gost != 17673) ) 
              {
                ::RFloatT( _T(IDS_DBCOLUMN_ALL) );
                ::RFloatT( _T(IDS_DBCOLUMN_ALL) );

                if ( (bolt.gost != 7801) || (bolt.gost != 7785) ) 
                {
                  ::RFloatT( _T(IDS_DBCOLUMN_ALL) );

                  if ( bolt.gost != 7802 ) 
                  {
                    ::RFloatT( _T(IDS_DBCOLUMN_ALL) );
                    ::RFloatT( _T(IDS_DBCOLUMN_ALL) );
                  }
                }
              }
            }
          ::EndRelation();

          if ( ::DoStatementT(bBase.bg, bBase.rs3, _T(STR_DB_READ_ALL)) ) // TXT_ALL
          {
            bBase.r1 = ::Relation( bBase.bs );            // Отношение для получения из базы диаметра конца
              ::RFloatT( _T(IDS_DBCOLUMN_DR) );
              ::RFloatT( _T(IDS_DBCOLUMN_Z4) );
              ::RFloatT( _T(IDS_DBCOLUMN_DP) );
            ::EndRelation();

            if ( ::DoStatementT(bBase.bs, bBase.r1, _T(STR_DB_READ_1_2_12)) ) // "1 2 12"
              okey = true;
          }
        }
      }
    }
  }
  return okey;
}


//------------------------------------------------------------------------------
// создание контура для очистки области под элементом
// ---
void BoltMain::CreateClearGroup()
{
  float radiusHead = (float)(bolt.d * 0.5);
  ::Circle( 0/*x центра*/, 0/*у центра*/, radiusHead + ADD_DIM/*радиус*/, BASE_LINE ); //Головка
}


//------------------------------------------------------------------------------
// чтение БД для составного элемента AssmElement
// ---
bool BoltMain::ReadElemBase( float d, float l, bool forAssmElem )
{
  bool goodRead = false;

  if ( bBase.bs && bBase.bg )
    if ( FillStruct(forAssmElem, d, l) )
      goodRead = true;

  return goodRead;
}


//------------------------------------------------------------------------------
// заполняет массив диаметров
// ---
void BoltMain::GetDiamArray( SArray<float> & diamArr )
{
  diamArr.Flush();
  TmpStruct diamRead;

  char buf[250];
  if ( ::DoStatement(bBase.bg, bBase.rs1, STR_DB_READ_2_2) ) // "2 2"
  {
    int i = 1;
    while ( i )                                           // Просматриваем все записи базы данных
    {
      i = ::ReadRecord( bBase.bg, bBase.rs1, &diamRead ); // Считываем данные

      if ( i ) 
      {
        if ( ::strcmp(buf, diamRead.s) )            // Если данное не повторяется
          diamArr.Add( (float)::atof(diamRead.s) ); // заносим его в список

        ::strcpy_s( buf, diamRead.s );              // Обновляем буфер
      }
    }
  }
}


//-------------------------------------------------------------------------------
//
// ---
void BoltMain::SetDrawType( short drawType )
{
  m_baseParam.drawType = (ushort)(drawType == ID_BOTTOM ? ID_BOTTOM : drawType); 
}


//-------------------------------------------------------------------------------
// рисовать ось 
// ---
void BoltMain::SetAxis( bool v ) 
{
  if ( v )
    bolt.f &= (short)~AXIS_OFF; // Снять флаг
  else
    bolt.f |= AXIS_OFF;         // Установить флаг
}


//-------------------------------------------------------------------------------
// Номер атрибута
// ---
double BoltMain::AttrNumber()
{
  return 313277777065.0;
}


//-------------------------------------------------------------------------------
// Заполнение объекта СП
// ---
bool BoltMain::_EditSpcObj( ksAPI7::ISpecificationBaseObjectPtr & obj1 )
{
  uint uBuf;
  ksAPI7::ISpecificationColumnsPtr columns = obj1->GetColumns();
  ksAPI7::ISpecificationColumnPtr column = columns->GetColumn( ksSColumnName, 1, 0 );
  ksAPI7::ISpecificationColumnItemsPtr columnItems = column->GetColumnItems();
  long n = columnItems->GetCount();
  ksAPI7::ISpecificationColumnItemPtr Item;

  if ( columnItems )
  {
    Item = columnItems->GetItem( 1 );
    if ( Item )
      Item->Visible = FALSE; // Выключим исполнение

    Item = columnItems->GetItem( 3 ); // Изменим диаметр
    if ( Item )
      Item->Value = bolt.dr;

    Item = columnItems->GetItem( 4 );
    if ( Item )
      Item->Visible = FALSE;

    Item = columnItems->GetItem( 5 );
    if ( Item )
      Item->Visible = FALSE; // выключим шаг

    Item = columnItems->GetItem( 6 );
    if ( Item )
      Item->Visible = FALSE; // выключим поле допуска

    uBuf = (uint)bolt.l;

    Item = columnItems->GetItem( 6 );
    if ( Item )
      Item->Value = uBuf; //изменим длину

    Item = columnItems->GetItem( 9 );
    if ( Item )
      Item->Visible = FALSE; // выключим класс прочности

    Item = columnItems->GetItem( 10 );
    if ( Item )
      Item->Visible = FALSE; // выключим материал

    Item = columnItems->GetItem( 11 );
    if ( Item )
      Item->Visible = FALSE; // выключим покрытие

    Item = columnItems->GetItem( 12 );
    if ( Item )
      Item->Value = ::LoadStr( IDS_GOST );

    Item = columnItems->GetItem( 13 );
    if ( Item )
      Item->Value = _T( "7787" );

    Item = columnItems->GetItem( 15 );
    if ( Item )
      Item->Value = _T( "81" );

    columns = obj1->AdditionalColumns;

    if ( columns )
    {
      column = columns->GetColumn( ksSColumnMass, 1, 0 );
      if ( column )
      {
        columnItems = column->GetColumnItems();
        if ( columnItems )
          columnItems->GetItem( 0 )->PutValue( bolt.m );
      }
    }
  }
 

  return true;
}


//-------------------------------------------------------------------------------
// Получить парметры для элемента XML дерева
// ---
void BoltMain::GetXMLPartFamilyParam( CString & name, CString & id )
{
  name = ::LoadStr( IDS_BOLT7787 );
  id   = ::LoadStr( IDS_BOLT7787_ID );
}



//------------------------------------------------------------------------------
// Создаёт группу объектов
// ---
void BoltMain::GetGroup()
{
  switch ( m_baseParam.drawType ) 
  {
    case ID_BOTTOM : BottomDraw(); break;   // вид снизу
    case ID_TOP    : TopDraw   (); break;   // вид ссверху
    default        : ViewDraw  (); break;   // вид
  }
}


//------------------------------------------------------------------------------
// Рисование оконтовки головки для болтов 7787(BoltMain), 7786 и 7785
// ---
void HalfSideHead( float x, float y, bool apl = false ) 
{
  ::LineSeg( 0, 0, 0, y, BASE_LINE );
  ::LineSeg( 0, y, x, y, BASE_LINE );
  if ( !apl )
    ::LineSeg( x, y, x, 0, BASE_LINE );
}


//------------------------------------------------------------------------------
// Рисование половины основного вида болта:
// downHalf = false - верхняя часть, true - нижняя
// ---
void BoltMain::ViewHalfDraw( bool downHalf, bool apl )
{
  int sign = downHalf ? -1 : 1;

  float radThr  = (float)(bolt.dr * 0.5);    // радиус резьбы
  float radHead = (float)(bolt.d  * 0.5);    // радиус головки

  int    kp;                        // кол-во точек пересечения
  double xp, yp;                    // координаты точки пересечения
  ::IntersectLinLin( bolt.k/*коор-та x*/, radThr/*коор-та у*/,  160/*угол*/,  // первая линия
                     0/*коор-та x*/,      radHead/*коор-та у*/, 0/*угол*/,    // вторая линия
                     &kp, &xp, &yp );                                         // возвращяемые значения

  if ( kp ) 
  {
    radHead *= sign;
    radThr *= sign;

    ::LineSeg( xp,     radHead, bolt.k, radThr, BASE_LINE );    // подголовник
    if ( !apl )
      ::LineSeg( bolt.k, radThr,  bolt.k, 0,      BASE_LINE );  // граница подголовка

    ::HalfSideHead( (float)xp, radHead, apl );                  // оконтовка головки
    ::BoltBarDraw( bolt, sign, apl );                           // стержень
  }
}


//------------------------------------------------------------------------------
// Рисование вида сверху
// ---
void BoltMain::TopDraw() 
{
  float radiusHead = (float)(bolt.d * 0.5);

  // Отрисовка апликативной заливки
  ksColouring( WORKWINDOWCOLOR );
  ::Circle( 0/*x центра*/, 0/*у центра*/, radiusHead/*радиус*/, BASE_LINE ); // Головка
  EndObj();

  // Отрисовка основной графики
  ::Circle( 0/*x центра*/, 0/*у центра*/, radiusHead/*радиус*/, BASE_LINE ); // Головка

  if ( !(bolt.f & AXIS_OFF) )                               // Оси
  {
    radiusHead += AXIS_END;
    ::LineSeg( radiusHead/*х нач. точки*/,  0/*у нач. точки*/,
               -radiusHead/*х кон. точки*/, 0/*у кон. точки*/, AXIS_LINE );
    ::LineSeg( 0, radiusHead, 0, -radiusHead, AXIS_LINE );
  }
}


//------------------------------------------------------------------------------
// Рисование основного вида болта
// ---
void BoltMain::ViewDraw()
{
  // Отрисовка апликативной заливки
  ksColouring( WORKWINDOWCOLOR );
    ViewHalfDraw( false/*downHalf*/, true/*apl*/ );  // верхняя часть
    ViewHalfDraw( true /*downHalf*/, true/*apl*/ );  // Нижняя часть
  EndObj();
  // Отрисовка основной графики
  ViewHalfDraw( false/*downHalf*/ );  // верхняя часть
  ViewHalfDraw( true /*downHalf*/ );  // Нижняя часть

  if ( !(bolt.f & AXIS_OFF) )         // оси
    ::LineSeg( - AXIS_END, 0, bolt.l + AXIS_END, 0, AXIS_LINE );
}


//------------------------------------------------------------------------------
// Рисование вида снизу
// ---
void BoltMain::BottomDraw()
{
  TopDraw();                          // Головка

  ::BoltBarBottomDraw( bolt );        // стержень
}


//------------------------------------------------------------------------------
// Перезаполняет структуру данными из базы в соответствии со значением длины и
// диаметра
// ---
bool BoltMain::FillStruct( bool forAssmElem, float d, float l ) 
{
  bool failDB = true; // предполагаем ошибку
  // Считываем из файла строку с форматом запроса к БД для выборки по полям
  // длина (L) и диаметр резьбы (dr)
  char buf [ 255 ];
  char buf1[ 128 ];
  if ( forAssmElem )
    // в buf формируем строку запрса с текущими значениями длины и диам.резьбы
    ::sprintf_s( buf, IDS_D_LB_CONDITION, l, d );  // "L>=%.0f && dr=%.0f"
  else
    // в buf формируем строку запрса с текущими значениями длины и диам.резьбы
    ::sprintf_s( buf, IDS_L_DRCONDITION, bolt.l, bolt.dr );  // "L=%.0f && dr=%.0f "

  if ( ::Condition(bBase.bg, bBase.rs3, buf) )   // Определяем условие запроса
  {
    BoltMainStruct tmpL( bolt );

    int i = ::ReadRecord( bBase.bg, bBase.rs3, &tmpL.l );// Считываем запись

    if ( i )                              // если запись найдена
    {
      bolt = tmpL;                        // переписать структуру

      // переписываем поле b определяя истинную длину резьбы, т.к. она зависит от
      // длины болта и от значения поля kr
      switch ( bolt.gost ) 
      {
        case 7786  :
        case 17673 :
        case 7785  :
          bolt.b = bolt.kr == 1
                        ? (bolt.l > 120)
                            ? bolt.gost == 7785
                                ? tmpL.h : tmpL.param2
                            : tmpL.b
                        : bolt.l - bolt.k; break; // длина резьбы

        case 7801  : 
        {
          bolt.b = bolt.kr == 1
                        ? (bolt.l > 120) ? tmpL.h : tmpL.b
                        : bolt.l - bolt.param1; // длина резьбы

          bolt.rp = bolt.v;                     // радиус под головкой
          bolt.v  = 0;
          break;
        }

        case 7802  : 
        {
          bolt.b = bolt.kr == 1
                        ? (bolt.l > 120) ? tmpL.d1 : tmpL.b
                        : bolt.l - bolt.v; // длина резьбы

          bolt.rp = bolt.h;                     // радиус под головкой
          bolt.h = 0;
          break;
        }

        case 7783  : bolt.b = bolt.kr == 1
                                   ? (bolt.l > 120) ? tmpL.b1 : tmpL.b
                                   : bolt.l - bolt.h; break; // длина резьбы
      }

      ::sprintf_s( buf1, READBYDIAM, bolt.dr );       // "dr=%.0f" - условие запроса
      if ( ::Condition( bBase.bs,  bBase.r1, buf1 ) ) // переопределяем условие
      {
        struct 
        {
          float dr;                                 // диаметр резьбы
          float z4;                                 // величина фаски
          float dp;                                 // диаметр конца стержня
        } tmpM;

        int i = ::ReadRecord( bBase.bs, bBase.r1, &tmpM );// Считываем запись
        if ( i ) 
        {
          bolt.dp = tmpM.dp;                     // Диаметр конца
          bolt.z4 = tmpM.z4;                     // величина фаски
          failDB  = false;                       // все получилось без ошибки
        }
      }
    }
  }

  return !failDB;
}


// HOT_POINTS ##################################################################
//------------------------------------------------------------------------------
//
// ---
bool BoltMain::GetHotPoints( HotPointDescription * point, int index ) 
{
  bool rez = false;
  bool stDraw = m_baseParam.drawType != ID_BOTTOM && m_baseParam.drawType != ID_TOP; // true - стержень рисуется
  
  switch ( index ) 
  {
    case 0 : // точка привязки
    {
      point->x = 0;
      point->y = 0;
      point->text = "0";
      rez = true;
      break;
    }
    case 1 : // Угол поворота
    {
      point->x = stDraw ? bolt.l / 3 : bolt.d * 0.5;
      point->y = 0;
      point->cursorInst = g_hInstance;
      point->cursorId   = CURSOR_ROTATE;
      point->text       = "A";
      rez = true;
      break;
    }
    case 2 : // Изменение диаметра
    {
      point->x = stDraw ? bolt.l : 0;
      point->y = bolt.dr * 0.5;
      point->cursorInst = g_hInstance;
      point->cursorId   = CURSOR_DIAMETER;
      point->text       = "Dr";
      rez = true;
      break;
    }
    case 3 : // Длина стержня болта
    {
      if ( stDraw ) {
        point->x = bolt.l;
        point->y = 0;
        point->cursorInst = g_hInstance;
        point->cursorId   = CURSOR_LENGHT;
        point->text       = "L";
        rez = true;
      }
      break;
    }
  }
  
  return rez;
}


//-------------------------------------------------------------------------------
// Параметры для Hot точек. Расширенное представление 
// ---
bool BoltMain::GetHotPointsEx( HotPointDescription1* point, int index )
{ 
  bool res = false;

  if ( point )
  {
    CString name;

    switch ( index ) 
    {
      case 0 : // Точка привязки
      {  
        name = _T("0");
        point->text = name.AllocSysString();
        res = true;
        break;
      }
    
      case 1 : // Угол поворота
      {  
        name = _T("A");
        point->text = name.AllocSysString();;
        res = true;
        break;
      }

      case 2 : // Изменение диаметра
      {  
        name = _T("Dr");
        point->text = name.AllocSysString();
        res = true;
        break;
      }

      case 3 : // Длина стержня болта
      {
        name = _T("L");
        point->text = name.AllocSysString();
        res = true;
        break;
      }
    }
  }
  return res;
}


//-------------------------------------------------------------------------------
//
// ---
bool BoltMain::GetCursorText( int index, char ** text )
{
  bool res = false;
  static char cursorText[255]; // обязательно должен быть описан как static
  switch ( index ) 
  {
    case 3 :
    {
      ::sprintf_s( cursorText, "L = %.2f", bolt.l );
      *text = cursorText;
      res = true;
      break;
    }
    case 2 :
    {
      ::sprintf_s( cursorText, "Dr = М%.2f", bolt.dr );
      *text = cursorText;
      res = true;
      break;
    }
    case 1 :
    {
      ::sprintf_s( cursorText, "A = %.2f", fmod(angle, 360.0) );
      *text = cursorText;
      res = true;
      break;
    }
    case 0 :
    {
      ::sprintf_s( cursorText, "X = %.2f\nY = %.2f", x, y );
      *text = cursorText;
      res = true;
      break;
    }
  }

  return res;
}


//-------------------------------------------------------------------------------
//
// ---
LPOLESTR BoltMain::GetCursorTextEx( int index )
{
  CString name;
  wchar_t cursorText[255]; // Изменяемый текст обязательно должен быть static

  switch ( index )
  {
    case 3 :
    {
      ::swprintf_s( cursorText, L"L = %.2f", bolt.l );
      name = cursorText;
      break;
    }
    case 2 :
    {
      ::swprintf_s( cursorText, L"Dr = М%.2f", bolt.dr );
      name = cursorText;
      break;
    }
    case 1 :
    {
      ::swprintf_s( cursorText, L"A = %.2f", angle );
      name = cursorText;
      break;
    }
    case 0 :
    {
      ::swprintf_s( cursorText, L"X = %.2f\nY = %.2f", x, y );
      name = cursorText;
      break;
    }
  }

  return name.AllocSysString();
};


//-------------------------------------------------------------------------------
//
// ---
bool BoltMain::ChangeHotPointParam( double d, double l, int index )
{
  bool retVal = false;

  if ( OpenBase() )
  {
    if ( index == 3 )
    {
      if ( l > 0 && ::fabs(l - bolt.l) > 0.01 )
        retVal = ReadElemBase( bolt.dr, (float)l, true/*forAssmElem*/ );
    }
    else 
    {
      TmpStruct tmpL;

      // подобрать ближайший dR по d
      double dR    = 0.0;
      double oldDR = bolt.dr;
      if ( !DoStatement(bBase.bg, bBase.rs1, STR_DB_READ_2_2) ) //"2 2"
        return false;

      while ( true ) 
      {
        if ( ::ReadRecord( bBase.bg, bBase.rs1, &tmpL ) )
        {
          if ( dR <= d )
            dR = tmpL.dr;
          else
            break;
        }
        else
          break;
      }

      if ( ::fabs(dR - oldDR) > 0.01 )
        retVal = ReadElemBase( (float)dR, bolt.l, true/*forAssmElem*/ );
    }
    CloseBase();
  }

  return retVal;
}


//------------------------------------------------------------------------------
//
// ---
bool BoltMain::SetHotPoint( HotPointDescription * point, int index ) 
{
  double x;
  double y;
  double alpha;
  if ( ::GetMacroPlacement(0, &x, &y, &alpha) )
  {
    switch ( index ) 
    {
      case 0 : // Хотточка перемещения 
      case 1 :
      {
        CPar::SetHotPoint( point, index );
        break;
      }
      case 2 :
      case 3 :
      {
        if ( ChangeHotPointParam(::fabs(point->y * 2), point->x, index) )
        {
          RedrawMacro();
// RA          reference gr = 0;
// RA          DrawGroup( gr );
// RA
// RA          SetParam();
// RA          ::SetMacroPlacement( refMacr, 0, 0, 0, 1 );
// RA          ::StoreTmpGroup( gr );
// RA          ::ClearGroup( gr );
        }
        break;
      }
    } // switch
  }

  return true;
}


// ША K8 //------------------------------------------------------------------------------
// ША K8 //
// ША K8 // ---
// ША K8 int BoltMain::GetMenu() {
// ША K8   HMENU menu = ::LoadMenu( _hInstance, MAKEINTRESOURCE(BOLT1_POPUPMENU) );
// ША K8   ::CheckMenuItem( menu, m_par.m_drawType, MF_BYCOMMAND | MF_CHECKED );
// ША K8   return int(menu);
// ША K8 }
// HOT_POINTS ##################################################################

// Окно свойств ##################################################################

//---------------------------------------------------------------------------------------------------- 
// Выдать идентификатор свойства по индексу
// ---
int BoltMain::GetPropertyID ( int index )
{
  int res = 0;
  switch ( index )
  {
    case 0 : res = ID_PROP_BOLT_PARAM     ; break; // Параметры элемента
    case 1 : res = ID_PROP_DIAMETER       ; break; // Диаметр
    case 2 : res = ID_PROP_LENGTH         ; break; // Длина
    case 3 : res = ID_PROP_BOLT_VIEW_PARAM; break; // Параметры отображения
    case 4 : res = ID_PROP_BOLT_VIEW      ; break; // Вид
    case 5 : res = ID_PROP_AXIS           ; break; // Рисовать ось
    case 6 : res = ID_PROP_OTHER_PARAM    ; break; // Справочные данные
    // Для примера свойств не описанных в ресурсах ----------------------
    case 7 : res = ID_PROP_OTHER_PARAM + 4; break; // Диаметр головки
    case 8 : res = ID_PROP_OTHER_PARAM + 5; break; // Высота головки
    case 9 : res = ID_PROP_OTHER_PARAM + 6; break; // Длина резьбы
    // ------------------------------------------------------------------
    case 10: res = ID_PROP_MASSA_1000     ; break; // Масса 1000 шт
  }
  return res;
}


//--------------------------------------------------------------------------
// Добавить свойство в список свойств
//---
BOOL BoltMain::GetProperty( int index, PropertyParam & param )
{
  param.propertyId = GetPropertyID( index );

  if ( param.propertyId )
  {
    param.propertyInstance = StepDLL.hModule;
    switch ( param.propertyId )
    {
      case ID_PROP_BOLT_PARAM      : // Параметры элемента
      case ID_PROP_BOLT_VIEW_PARAM : // Параметры отображения
      case ID_PROP_OTHER_PARAM     : // Справочные данные
      {
        param.propertyType = ksOPControlGroup; // Группа
        param.enable = true;
        break;
      }
      case ID_PROP_DIAMETER:      // Диаметр
      {
        param.propertyType         = ksOPControlListDouble; // Вещественный комбобокс
        param.propertyValue.vt     = VT_R8;
        param.propertyValue.dblVal = 0.0;
        param.enable   = true;
        param.readOnly = true;
        break;
      }
      case ID_PROP_LENGTH:        // Длина
      {
        param.propertyType         = ksOPControlListDouble; // Вещественный комбобокс
        param.propertyValue.vt     = VT_R8;
        param.propertyValue.dblVal = 0.0;
        param.enable   = true;
        param.readOnly = true;
        break;
      }
      case ID_PROP_BOLT_VIEW:     // Вид
      {
        param.propertyType       = ksOPControlListBmp;      // Список с иконками
        param.propertyValue.vt   = VT_I4;
        param.propertyValue.lVal = 0;
        param.enable = true;
        break;
      }
      case ID_PROP_AXIS:          // Ось
      {
        param.propertyType         = ksOPControlListCheck;  // Логическое значение Да \ Нет
        param.propertyValue.vt     = VT_BOOL;
        param.propertyValue.boolVal= VARIANT_FALSE;
        param.enable = true;
        break;
      }
    }

    if ( param.propertyId > ID_PROP_OTHER_PARAM && param.propertyId < ID_PROP_OTHER_PARAM_END )
    {
      param.propertyType  = ksOPControlEditDouble;   // Вещественный комбобокс
      param.propertyValue.vt = VT_R8;
      param.propertyValue.dblVal = 0.0;
      param.enable = false;                          // Не редактируется

      int nameId = 0;
      switch ( param.propertyId )
      {
        case (ID_PROP_OTHER_PARAM + 4): nameId = IDS_HEAD_DIAM;     break; // Диаметр головки
        case (ID_PROP_OTHER_PARAM + 5): nameId = IDS_HEAD_H;        break; // Высота головки
        case (ID_PROP_OTHER_PARAM + 6): nameId = IDS_THREAD_LENGTH; break; // Длина резьбы
        case ID_PROP_MASSA_1000       : nameId = IDS_MASSA_1000;    break; // Масса 1000 шт
      }

      param.displayPropertyName = CString(LoadStr(nameId)).AllocSysString();
    }
  }
  return !!param.propertyId;
}


//--------------------------------------------------------------------------
// Обновить параметры свойства
//---
BOOL BoltMain::UpdateProperty( PropertyParam & param )
{
  BOOL res = FALSE;

  if ( refMacr && param.propertyId == GetPropertyID(0) )
    GetMacroParam(refMacr, *this, Size()); // Возможно элемент уже изменили

  param.propertyInstance = StepDLL.hModule;
  switch ( param.propertyId )
  {
    case ID_PROP_BOLT_VIEW: // Вид
    {
      long view = IDP_BOLT_VIEW;
      switch ( m_baseParam.drawType )
      {
        case ID_VIEW   : view = IDP_BOLT_VIEW;   break; // Вид
        case ID_TOP    : view = IDP_BOLT_TOP;    break; // Вид сверху
        case ID_BOTTOM : view = IDP_BOLT_BOTTOM; break; // Вид снизу
      }
      param.propertyValue.lVal = view;
      res = TRUE;
      break;
    }
    case ID_PROP_AXIS:   // Ось
    {
      param.propertyValue.boolVal= GetAxis();
      res = TRUE;
      break;
    }
    case ID_PROP_DIAMETER:   // Диаметр
    {
      param.propertyValue.dblVal = bolt.dr;
      if ( param.additionData.vt != (VT_ARRAY | VT_R8) ) // Повторно не перенакачиваем
      {
        SArray<double> diamList;
        GetDiamList( diamList );
        CopySArrayToVariant( diamList, param.additionData );
      }
      res = TRUE;
      break;
    }
    case ID_PROP_LENGTH:   // Длина
    {
      param.propertyValue.dblVal = bolt.l;
      if ( param.additionData.vt != (VT_ARRAY | VT_R8) ) // Повторно не перенакачиваем
      {
        SArray<double> lengthList;
        GetLengthList( lengthList );
        CopySArrayToVariant( lengthList, param.additionData );
      }
      res = TRUE;
      break;
    }
    // Для примера свойств не описанных в ресурсах
    case (ID_PROP_OTHER_PARAM + 4): param.propertyValue.dblVal = bolt.d; res = TRUE; break; // "Диаметр головки"
    case (ID_PROP_OTHER_PARAM + 5): param.propertyValue.dblVal = bolt.k; res = TRUE; break; // "Высота головки"
    case (ID_PROP_OTHER_PARAM + 6): param.propertyValue.dblVal = bolt.b; res = TRUE; break; // "Длина резьбы"
    case ID_PROP_MASSA_1000       : param.propertyValue.dblVal = bolt.m; res = TRUE; break; // "Масса 1000 шт"
  }
  return res;
}


//--------------------------------------------------------------------------
// Изменить свойойство
//---
BOOL BoltMain::ApplyProperty( PropertyParam & param )
{
  int res = 0;
  switch ( param.propertyId )
  {
    case ID_PROP_DIAMETER:   // Диаметр
    {
      OpenBase();
      res = !!OnChangeControlValue( IDC_DIAMETER, param.propertyValue );
      CloseBase();
      break;
    }
    case ID_PROP_LENGTH:   // Длина
    {
      OpenBase();
      res = !!OnChangeControlValue( IDC_LENGTH, param.propertyValue );
      CloseBase();
      break;
    }
    case ID_PROP_BOLT_VIEW: // Вид
    {
      short view = ID_VIEW;
      switch ( param.propertyValue.lVal )
      {
        case IDP_BOLT_VIEW   : view = ID_VIEW;    break; // Вид 
        case IDP_BOLT_TOP    : view = ID_TOPVID;  break; // Вид сверху
        case IDP_BOLT_BOTTOM : view = ID_BOTTOM;  break; // Вид снизу
      }
      m_baseParam.drawType = view;
      res = 1;
      break;
    }
    case ID_PROP_AXIS:   // Ось
    {
      SetAxis( !!param.propertyValue.boolVal );
      res = 1;
      break;
    }
  }

  if ( res )
    changed = true;

  return res;
}


//---------------------------------------------------------------------------------------------------- 
// Имя группы
// ---
LPOLESTR BoltMain::GetGroupName()
{
  CString name( LoadStr(IDP_BOLT7787) );
  return name.AllocSysString();
}


//---------------------------------------------------------------------------------------------------- 
// Имя группы
// ---
LPCTSTR BoltMain::GetObjName()
{
  return LoadStr(IDP_BOLT7787);
}
// Окно свойств ##################################################################


// Панель свойств ##################################################################
//-------------------------------------------------------------------------------
// Виртуальная функция наполнения контролов элемента
// ---
void BoltMain::ShowControls()
{
  // Комбобокс диаметров резьбы
  ksAPI7::IPropertyListPtr diamList( CreateList() );
  if ( diamList ) 
  {
    InitPropertyControl( diamList, IDC_DIAMETER, IDC_DIAMETER_BOLT_HINT/*hint*/, IDC_DIAMETER_BOLT_TIPS/*tips*/ );
    FillDiamList       ( diamList );
  }

  // Комбобокс длин
  ksAPI7::IPropertyListPtr lengthList( CreateList() );
  if ( lengthList ) 
  {
    InitPropertyControl( lengthList, IDC_LENGTH, IDC_LENGTH_BOLT_HINT/*hint*/, IDC_LENGTH_BOLT_TIPS/*tips*/ );

    FillLengthList     ( lengthList );
  }

  // Отображение
  CreateSeparator( ksSeparatorDownName );
  ksAPI7::IPropertyMultiButtonPtr buttons( CreateMultiButton(ksRadioButton) );
  if ( buttons )
  {
    InitPropertyControl( buttons, IDP_REFLECTION, IDS_REFLECTION_HINT/*hint*/, IDS_REFLECTION_TIPS/*tips*/, TRUE, ksNameVerticalVisible );

    AddButton2( buttons, IDP_BOLT_VIEW, IDF_BOLT_VIEW, m_baseParam.drawType == ID_VIEW   ); // Кнопка вид
    AddButton2( buttons, IDP_BOLT_TOP, IDF_BOLT_TOP, m_baseParam.drawType == ID_TOP ); // Кнопка сверху 
    AddButton2( buttons, IDP_BOLT_BOTTOM, IDF_BOLT_BOTTOM, m_baseParam.drawType == ID_BOTTOM ); // Кнопка снизу
  }

  // Рисовать ось
  CreateSeparator( ksSeparatorDownName );
  ksAPI7::IPropertyMultiButtonPtr axisBtn( CreateMultiButton(ksCheckButton) );
  if ( axisBtn ) 
  {
    InitPropertyControl( axisBtn, IDC_AXIS, IDC_AXIS_HINT/*hint*/, IDC_AXIS_TIPS/*tips*/, TRUE, ksNameVerticalVisible );
    AddButton2( axisBtn, ID_AXIS, 0xe018, GetAxis() );
  }

  // Создавать объект спецификации
  CPar::ShowControls();
}


//-------------------------------------------------------------------------------
// Реакция на кнопки 
// ---
bool BoltMain::OnButtonClick( long buttonID ) // prButtonClick        - Нажатие кнопки.
{
  bool res = false;
  
  switch ( buttonID ) 
  {
    case IDP_BOLT_VIEW: // Вид
    { 
      m_baseParam.drawType = ID_VIEW;
      SetChange();
      Draw1();
      res = true;
      break; 
    }

    case IDP_BOLT_TOP: // Вид сверху
    { 
      m_baseParam.drawType = ID_TOP;
      Draw1();
      SetChange();
      res = true;
      break; 
    }

    case IDP_BOLT_BOTTOM: // Вид снизу
    { 
      m_baseParam.drawType = ID_BOTTOM;
      SetChange();
      Draw1();
      res = true;
      break; 
    }

    case ID_AXIS : // Рисовать ось
    {
      SetAxis( !GetAxis() );
      SetChange();
      Draw1();
      res = true;
      break;
    }
    case ID_LEADER_CREATE: // Создать новую линию выноски
    {
      if (newKompasAPI)
      {
        // Остановка текущего процесса.
        newKompasAPI->StopCurrentProcess(TRUE, NULL);// Должно быть true
        processState = ProcessState::processCreateLeader;
      }
    }
    break;
  }

  return res;  
}


//-------------------------------------------------------------------------------
// prChangeControlValue - Изменение значения контрола
// ---
bool BoltMain::OnChangeControlValue( long ctrlID, const VARIANT & newVal )
{
  bool res = false;
  
  switch ( ctrlID ) 
  {
    case IDC_DIAMETER: // Диаметр 
    { 
      float diam = (float)newVal.dblVal; 
      if ( ::fabs(diam - bolt.dr) > 0.001 ) 
      {
        bolt.dr = diam;

        ksAPI7::IPropertyListPtr lengthList( GetPropertyControl(IDC_LENGTH) );
        FillLengthList( lengthList ); // Перезаполняем список "Длина"

        if ( FillStruct() )           // Считываем остальные данные из базы
        {
          SetChange();                // надо перерисовать
          res = true;
        }
      }
      break; 
    }

    case IDC_LENGTH: // Длина
    { 
      float ln = (float)newVal.dblVal; 
      if ( ::fabs(ln - bolt.l) > 0.001 ) 
      {
        bolt.l = ln;

        if ( FillStruct() ) // Считываем остальные данные из базы
        {
          SetChange();      // надо перерисовать
          res = true;
        }
      }
      break; 
    }

    default : res = CPar::OnChangeControlValue( ctrlID, newVal );
  }

  return res;  
}


//-------------------------------------------------------------------------------
// Заполнение списка диаметров резьбы
// ---
void BoltMain::FillDiamList(ksAPI7::IPropertyListPtr & diamList )
{
  // Заполнение комбобокса
  TmpStruct tmpL;

  float oldDr = 0;
  int   i     = 1;

  while ( i )                                        // Просматриваем все записи базы данных
  {
    i = ::ReadRecord( bBase.bg, bBase.rs1, &tmpL );  // Считываем данные

    if ( i ) 
    {
      if ( oldDr != tmpL.dr )                        // Если данное не повторяется
        diamList->Add( _variant_t(tmpL.dr, VT_R8) ); // заносим его в список

      oldDr = tmpL.dr;                               // Обновляем буфер
    }
  }

  diamList->Value = _variant_t( bolt.dr ); // Считываем значение диаметра из структуры и выделяем его в списке

  if ( bolt.gost == 7787 )
    diamList->Enable = FALSE;
}


//-------------------------------------------------------------------------------
// Заполнение списка длин
// ---
void BoltMain::FillLengthList(ksAPI7::IPropertyListPtr & lengthList )
{
  TmpStruct tmpL;

  ::sprintf_s( tmpL.s, READBYDIAM, bolt.dr );          // "dr=%.0f" - условие запроса

  if ( ::Condition(bBase.bg,  bBase.rs2, tmpL.s) ) { // переопределяем условие
    lengthList->ClearList();                         // Очищаем содержимое списка "Длина"

    int    i    = 1;
    double lMin = MAX_LENGTH;
    double lMax = MIN_LENGTH;

    while ( i ) {                                    // Просматриваем все записи базы данных
      i = ::ReadRecord( bBase.bg, bBase.rs2, &tmpL );// Считываем данное

      if ( i ) {
        char *c;
        double ln = ::strtod( tmpL.s, &c );          // Преобразуем его в число

        lengthList->Add( _variant_t(ln, VT_R8) );    // Заносим его в список

        if ( ln < lMin )
          lMin = ln;                                 // находим минимальное значение

        if ( ln > lMax )
          lMax = ln;                                 // находим максимальное значение
      }
    }

    if ( bolt.l < lMin )     // если длина выходит за минимальную границу новых значений
      bolt.l = (float)lMin;  // присваиваем ей минимальное значение

    if ( bolt.l > lMax )     // если длина выходит за максимальную границу новых значений
      bolt.l = (float)lMax;  // присваиваем ей максимальное значение
  }

  lengthList->Value = _variant_t( bolt.l ); // Считываем значение длины из структуры и выделяем его в списке
}


//-------------------------------------------------------------------------------
// Получить массив диаметров
// ---
bool BoltMain::GetDiamList( SArray<double> & diamList )
{
  diamList.HardFlush();
  if ( OpenBase() )
  {
    TmpStruct tmpL;
    float oldDr = 0;
    int   i     = 1;

    while ( i )                                        // Просматриваем все записи базы данных
    {
      i = ::ReadRecord( bBase.bg, bBase.rs1, &tmpL );  // Считываем данные

      if ( i ) 
      {
        if ( oldDr != tmpL.dr )    // Если данное не повторяется
          diamList.Add( tmpL.dr ); // заносим его в список

        oldDr = tmpL.dr;           // Обновляем буфер
      }
    }
    CloseBase();
  }
  return !!diamList.Count();
}


//-------------------------------------------------------------------------------
// Получить массив длин
// ---
bool BoltMain::GetLengthList( SArray<double> & lengthList )
{
  lengthList.HardFlush();
  if ( OpenBase() )
  {
    TmpStruct tmpL;
    ::sprintf_s( tmpL.s, READBYDIAM, bolt.dr );          // "dr=%.0f" - условие запроса

    if ( ::Condition(bBase.bg,  bBase.rs2, tmpL.s) )
    {
      int    i    = 1;
      double lMin = MAX_LENGTH;
      double lMax = MIN_LENGTH;

      while ( i ) {                                    // Просматриваем все записи базы данных
        i = ::ReadRecord( bBase.bg, bBase.rs2, &tmpL );// Считываем данное

        if ( i ) {
          char *c;
          double ln = ::strtod( tmpL.s, &c );          // Преобразуем его в число

          lengthList.Add( ln );                        // Заносим его в список

          if ( ln < lMin )
            lMin = ln;                                 // находим минимальное значение

          if ( ln > lMax )
            lMax = ln;                                 // находим максимальное значение
        }
      }

      if ( bolt.l < lMin )     // если длина выходит за минимальную границу новых значений
        bolt.l = (float)lMin;  // присваиваем ей минимальное значение

      if ( bolt.l > lMax )     // если длина выходит за максимальную границу новых значений
        bolt.l = (float)lMax;  // присваиваем ей максимальное значение
    }
    CloseBase();
  }
  return !!lengthList.Count();
}


//-------------------------------------------------------------------------------
// Заполнение грида параметров 
// ---
void BoltMain::ShowParam()
{
  AddDoubleToGrig( IDS_HEAD_DIAM,   bolt.d ); // Диаметр головки
  AddDoubleToGrig( IDS_HEAD_HEIGHT, bolt.k ); // Высота головки

//   switch ( lpBolt.bolt.gost )
//   {
//     case 7785  : {

// ША K8       viewParam->AddParItem( &lpBolt.bolt.v,      pmFloat, BSTR268 ); // "Ширина уса"
// ША K8       viewParam->AddParItem( &lpBolt.bolt.param2, pmFloat, BSTR270 ); // "угол"
// ША K8       viewParam->AddParItem( &lpBolt.bolt.param1, pmFloat, BSTR269 ); // "Высота уса"
// ША K8       break; }
// ША K8 
// ША K8     case 17673 :
// ША K8     case 7786  : {
// ША K8       viewParam->AddParItem( &lpBolt.bolt.param1, pmFloat, BSTR255 ); // "Сторона подголовка"
// ША K8       break; }
// ША K8 
// ША K8     case 7783  :
// ША K8     case 7801  : {
// ША K8       viewParam->AddParItem( &lpBolt.bolt.param2, pmFloat, BSTR253 ); // "Радиус сферы"
// ША K8       viewParam->AddParItem( &lpBolt.bolt.param1, pmFloat, BSTR269 ); // "Высота уса"
// ША K8       if ( lpBolt.bolt.gost == 7783 ) {
// ША K8         viewParam->AddParItem( &lpBolt.bolt.h,     pmFloat, BSTR267 ); // "Высота подголовка"
// ША K8         viewParam->AddParItem( &lpBolt.bolt.v,     pmFloat, BSTR268 ); // "Ширина уса"
// ША K8       }
// ША K8       break; }
// ША K8 
// ША K8     case 7802  : {
// ША K8       viewParam->AddParItem( &lpBolt.bolt.param2, pmFloat, BSTR253 ); // "Радиус сферы"
// ША K8       viewParam->AddParItem( &lpBolt.bolt.v,      pmFloat, BSTR254 ); // "Высота подголовка"
// ША K8       viewParam->AddParItem( &lpBolt.bolt.param1, pmFloat, BSTR255 ); // "Размер стороны подголовка"
// ША K8 
// ША K8       break; }
// ША K8   }
// ША K8 
  AddDoubleToGrig( IDS_THREAD_LENGTH, bolt.b  ); // Длина резьбы
  AddDoubleToGrig( IDS_MASSA_1000,    bolt.m  ); // Масса 1000 шт
}


//---------------------------------------------------------------------------
// создать группу для вывода в окне
// ---
reference BoltMain::GetPreviewGroup()
{
  reference gr = 0;

  BoltMain tmpBolt( *this );       // Создаем временный объект
  tmpBolt.GetParam().Init();       // Параметры по умолчанию

// ША K8+   BoltMainStruct tmp    ( GetParam() );  // сохраняем параметры во временном буфере  GetParam().Init();
// ША K8+   GetParam().Init();                     // Параметры по умолчанию
// ША K8+   GetParam().Assign( tmp );              // восстановление прежних параметров

  tmpBolt.DrawGroup( gr );

  return gr;
}
// Панель свойств ##################################################################


// ША K8 ////////////////////////////////////////////////////////////////////////////////
// ША K8 //
// ША K8 // Класс Bolt7786
// ША K8 // Болт ГОСТ 7786-81 и ГОСТ 17673-81
// ША K8 //
// ША K8 ////////////////////////////////////////////////////////////////////////////////
// ША K8 class Bolt7786 : public BoltMain {
// ША K8 public:
// ША K8   Bolt7786( ushort gost );
// ША K8   // конструктор - для состовного объекта
// ША K8   Bolt7786( ushort _gost, short _type, char** pBuf, BaseMakroParam* _par );
// ША K8   virtual int   Size() { return ConstrObject::Size() + 48; }
// ША K8   Bolt7786*     Dublicate();                    // оператор копирования
// ША K8   virtual ConstrObject* DublicateObj();
// ША K8 
// ША K8 protected:
// ША K8   virtual bool  IsSimpleModeAvaible() { return false; } // для составного элемента рисовать детали упрощенно
// ША K8   virtual void  ViewHalfDraw( bool downHalf );  //Рисует половину основного вида
// ША K8   virtual void  BottomDraw();                   // рисует вид снизу
// ША K8 };
// ША K8 
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // Конструктор
// ША K8 // ---
// ША K8 Bolt7786::Bolt7786( ushort gost )
// ША K8   : BoltMain( gost ) {
// ША K8   if ( bolt.gost != 7802 )
// ША K8     InitBolt();
// ША K8 }
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // конструктор - для состовного объекта
// ША K8 // ---
// ША K8 Bolt7786::Bolt7786( ushort _gost, short _type, char** pBuf, BaseMakroParam* _par )
// ША K8   : BoltMain( _gost, _type, pBuf, _par ) {
// ША K8 //    !!! Внимание если появится версия то size должен быть посчитан с учетом версии !!!
// ША K8   if ( pBuf && *pBuf ) 
// ША K8     *pBuf = (char*)_par + Size(); // смещаем указатель на размер данных
// ША K8 }
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // конструктор копии
// ША K8 // ---
// ША K8 Bolt7786* Bolt7786::Dublicate() {
// ША K8   return new Bolt7786( *this );
// ША K8 }
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // конструктор копии
// ША K8 // ---
// ША K8 ConstrObject* Bolt7786::DublicateObj() {
// ША K8   return new Bolt7786( *this );
// ША K8 };
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // Рисует вид снизу
// ША K8 // ---
// ША K8 void Bolt7786::BottomDraw() {
// ША K8   TopDraw();                          // Головка
// ША K8 
// ША K8   ::BoltBarBottomDraw( bolt );        // стержень
// ША K8 
// ША K8   // квадрат подголовка
// ША K8   float sideHead = bolt.param1 * sqrt(0.5);
// ША K8   ::LineSeg( 0/*x нач. точки*/, sideHead/*y нач. точки*/,
// ША K8              - sideHead/*x кон. точки*/, 0/*y кон. точки*/, BASE_LINE );
// ША K8   ::LineSeg( - sideHead,  0,        0,        - sideHead, BASE_LINE );
// ША K8   ::LineSeg(   0,       - sideHead, sideHead,   0,        BASE_LINE );
// ША K8   ::LineSeg(   sideHead,  0,        0,          sideHead, BASE_LINE );
// ША K8 }
// ША K8 
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // Рисование половины основного вида болта:
// ША K8 // downHalf = false - верхняя часть, true - нижняя
// ША K8 // ---
// ША K8 void Bolt7786::ViewHalfDraw( bool downHalf ) {
// ША K8   int sign = downHalf ? -1 : 1;
// ША K8 
// ША K8   float sideHead = bolt.param1 * sqrt(0.5); // сторона подголовка
// ША K8   float radHead  = bolt.d * 0.5;            // радиус головки
// ША K8 
// ША K8   int    kp;                           // кол-во точек пересечения
// ША K8   double xp, yp;                       // координаты точки пересечения
// ША K8 
// ША K8   int angle = bolt.gost == 17673 ? 120 : 135; // угол наклона второй линии
// ША K8   ::IntersectLinLin( bolt.k/*коор-та x*/, sideHead/*коор-та у*/,  0/*угол*/,    // первая линия
// ША K8                      1/*коор-та x*/,      radHead/*коор-та у*/,   angle/*угол*/,// вторая линия
// ША K8                      &kp, &xp, &yp );                                           // возвращяемые значения
// ША K8 
// ША K8   int    kp1;                       // кол-во точек пересечения
// ША K8   double xp1, yp1;                  // координаты точки пересечения
// ША K8   ::IntersectHeadRestFaset( bolt, kp1, xp1, yp1 ); // пересечение стороны подголовка и его фаски
// ША K8 
// ША K8   if ( kp && kp1 ) {
// ША K8     radHead *= sign;
// ША K8     ::HalfSideHead( 1, radHead );           // оконтовка головки
// ША K8 
// ША K8     yp *= sign;
// ША K8     ::LineSeg( 1, radHead, xp, yp,      BASE_LINE );       // головка
// ША K8     ::ArcBy3Points( xp, yp, xp + (bolt.k - xp1) * 0.7, yp * 0.5, xp, 0, BASE_LINE );
// ША K8 
// ША K8     yp1 *= sign;
// ША K8     ::LineSeg( xp, yp, xp1, yp1, BASE_LINE );              // верхняя/нижняя грань подголовка
// ША K8     ::LineSeg( xp, 0,  xp1, 0,   BASE_LINE );              // средняя грань подголовка
// ША K8 
// ША K8     float radThr = sign * bolt.dr * 0.5;     // радиус резьбы
// ША K8     ::ArcBy3Points( xp1 + (bolt.k - xp1) * 0.5/*x первой точки*/,
// ША K8                     radThr + (yp1 - radThr) * 0.5/*у первой точки*/,
// ША K8                     bolt.k/*x второй точки*/, sign * sideHead * 0.5/*у второй точки*/,
// ША K8                     xp1/*x третьей точки*/, 0/*у третьей точки*/, BASE_LINE );
// ША K8 
// ША K8     ::LineSeg( xp1,    yp1,    bolt.k, radThr, BASE_LINE ); // фаска подголовка
// ША K8     ::LineSeg( bolt.k, radThr, bolt.k, 0,      BASE_LINE ); // граница подголовка
// ША K8 
// ША K8     ::LineSeg( xp,  yp,  xp1, 0, SLIM_LINE );  //Обозначение плоскости
// ША K8     ::LineSeg( xp1, yp1, xp,  0, SLIM_LINE );
// ША K8 
// ША K8     ::BoltBarDraw( bolt, sign );               // стержень
// ША K8   }
// ША K8 }
// ША K8 
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // пересечение сферы головки и грани её оконтовки 7801, 7802
// ША K8 // ---
// ША K8 void IntersectHead( const BoltMainStruct &bolt,
// ША K8                     int &kp, double xp[], double yp[] ) {
// ША K8   float radHead = bolt.d * 0.5;                        // радиус головки
// ША K8   float xCenter = bolt.param2 - bolt.k;                // координата х центра сферы
// ША K8 
// ША K8   // пересечение сферы головки и грани её оконтовки
// ША K8   ::IntersectLinSCir( 0, radHead, (- bolt.k), radHead, // отрезок
// ША K8                       xCenter, 0, bolt.param2,         // окружность
// ША K8                       &kp, xp, yp );                   // возвращаемые значения
// ША K8 }
// ША K8 
// ША K8 
// ША K8 
// ША K8 ////////////////////////////////////////////////////////////////////////////////
// ША K8 //
// ША K8 // Класс Bolt7802
// ША K8 // Болт ГОСТ 7802-81
// ША K8 //
// ША K8 ////////////////////////////////////////////////////////////////////////////////
// ША K8 class Bolt7802 : public Bolt7786 {
// ША K8 public:
// ША K8   Bolt7802() : Bolt7786( 7802 ) { InitBolt(); }
// ША K8   // конструктор - для состовного объекта
// ША K8   Bolt7802( short _type, char** pBuf, BaseMakroParam* _par );
// ША K8   virtual int   Size() { return ConstrObject::Size() + 56; }
// ША K8   Bolt7802*     Dublicate();                    // оператор копирования
// ША K8   virtual ConstrObject* DublicateObj();
// ША K8 
// ША K8 protected:
// ША K8   virtual bool  IsSimpleModeAvaible() { return false; } // для составного элемента рисовать детали упрощенно
// ША K8   virtual void  ViewHalfDraw( bool downHalf );  // Рисует половину основного вида
// ША K8   virtual void  ViewDraw();                     // рисует основной вид
// ША K8   virtual void  SetSimpleMode( bool ) {}        // для составного элемента рисовать детали упрощенно
// ША K8 };
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 //
// ША K8 // ---
// ША K8 Bolt7802::Bolt7802( short _type, char** pBuf, BaseMakroParam* _par )
// ША K8   : Bolt7786( 7802, _type, pBuf, _par ) {
// ША K8 //    !!! Внимание если появится версия то size должен быть посчитан с учетом версии !!!
// ША K8   if ( pBuf && *pBuf ) 
// ША K8     *pBuf = (char*)_par + Size(); // смещаем указатель на размер данных
// ША K8 }
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // конструктор копии
// ША K8 // ---
// ША K8 Bolt7802* Bolt7802::Dublicate() {
// ША K8   return new Bolt7802( *this );
// ША K8 }
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // конструктор копии
// ША K8 // ---
// ША K8 ConstrObject* Bolt7802::DublicateObj() {
// ША K8   return new Bolt7802( *this );
// ША K8 };
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // Рисование основного вида болта
// ША K8 // ---
// ША K8 void Bolt7802::ViewDraw() {
// ША K8   ViewHalfDraw( false/*downHalf*/ );  // верхняя часть
// ША K8   ViewHalfDraw( true /*downHalf*/ );  // Нижняя часть
// ША K8 
// ША K8   ::BoltAxisDraw( bolt );             // оси
// ША K8 }
// ША K8 
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // Рисование половины основного вида болта:
// ША K8 // downHalf = false - верхняя часть, true - нижняя
// ША K8 // ---
// ША K8 void Bolt7802::ViewHalfDraw( bool downHalf ) {
// ША K8   int sign = downHalf ? -1 : 1;
// ША K8 
// ША K8   int    kp;                                                   // кол-во точек пересечения
// ША K8   double xp[2], yp[2];                                         // координаты точки пересечения
// ША K8   ::IntersectHead( bolt, kp, xp, yp );                         // пересечение сферы и оконтовки головки
// ША K8 
// ША K8   if ( kp != 0 ) {                                             // Головка
// ША K8     float yCoor   = sign * yp[0];
// ША K8     float xCenter = bolt.param2 - bolt.k;                      // координата х центра сферы
// ША K8     ::ArcByPoint( xCenter/*x центра*/,     0/*y центра*/,         bolt.param2/*радиус*/,
// ША K8                   xp[0]/*x нач. точки*/,   yCoor/*y нач. точки*/,
// ША K8                   -bolt.k/*x кон. точки*/, 0/*y кон. точки*/,
// ША K8                   (short) sign/*направление*/,     BASE_LINE );
// ША K8 
// ША K8     float radHead = bolt.d * 0.5;                                // радиус головки
// ША K8     float yHead   = sign * radHead;
// ША K8     ::LineSeg( xp[0]/*x нач. точки*/, yCoor/*y нач. точки*/,
// ША K8                0/*x кон. точки*/, yHead/*y кон. точки*/, BASE_LINE );
// ША K8     ::LineSeg( xp[0], yCoor, xp[0], 0, BASE_LINE );
// ША K8     ::LineSeg( 0,     yHead, 0,     0, BASE_LINE );
// ША K8 
// ША K8     if ( !(bolt.f & DRAW_ST_OF) ) {                             // Рисовать стержень?
// ША K8       int kp1;
// ША K8       double xp1, yp1;
// ША K8       ::IntersectHeadRestFaset( bolt, kp1, xp1, yp1 );
// ША K8 
// ША K8       if ( kp1 ) {
// ША K8         yp1 *= sign;
// ША K8         float sideHead = sign * bolt.param1 * sqrt(0.5);          // сторона подголовка
// ША K8         float radThr   = sign * bolt.dr * 0.5;                    // радиус резьбы
// ША K8         ::ArcBy3Points( xp1 + (bolt.v - xp1) * 0.5/*x первой точки*/,
// ША K8                         radThr + (yp1 - radThr) * 0.5/*у первой точки*/,
// ША K8                         bolt.v/*x второй точки*/, sideHead * 0.5/*у второй точки*/,
// ША K8                         xp1/*x третьей точки*/,   0/*у третьей точки*/, BASE_LINE );
// ША K8 
// ША K8         ::LineSeg( xp1,    yp1,      bolt.v, radThr, BASE_LINE ); // фаска подголовка
// ША K8         ::LineSeg( bolt.v, radThr,   bolt.v, 0,      BASE_LINE ); // граница подголовка со стержнем
// ША K8         ::LineSeg( 0,      sideHead, xp1,    yp1,    BASE_LINE ); // Подголовник - верхняя грань
// ША K8         ::LineSeg( xp1,    0,        0,      0,      BASE_LINE ); // средняя грань
// ША K8         ::LineSeg( xp1,    yp1,      0,      0,      SLIM_LINE ); // обозначение
// ША K8         ::LineSeg( 0,      yp1,      xp1,    0,      SLIM_LINE ); // плоскости
// ША K8 
// ША K8         ::BoltBarDraw( bolt, sign );                           // стержень
// ША K8       }
// ША K8     }
// ША K8   }
// ША K8 }
// ША K8 
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // точка пересечения головки и средней грани уса( вершина уса ) 7801
// ША K8 // ---
// ША K8 void IntersectHeadPin( const BoltMainStruct &bolt,
// ША K8                        int &kp1, double &xp1, double &yp1 ) {
// ША K8 
// ША K8   float radThr = bolt.dr * 0.5;     // радиус резьбы
// ША K8                      /*коор-та x*/  /*коор-та у*/ /*угол*/
// ША K8   ::IntersectLinLin( 0,             0,            90,       // первая линия
// ША K8                      bolt.param1,   radThr,       225,      // вторая линия
// ША K8                      &kp1, &xp1, &yp1 );                    // возвращяемые значения
// ША K8 }
// ША K8 
// ША K8 
// ША K8 
// ША K8 ////////////////////////////////////////////////////////////////////////////////
// ША K8 //
// ША K8 // Класс Bolt7801
// ША K8 // Болт ГОСТ 7801-81
// ША K8 //
// ША K8 ////////////////////////////////////////////////////////////////////////////////
// ША K8 class Bolt7801  : public BoltMain {
// ША K8 public:
// ША K8   Bolt7801() : BoltMain( 7801 ) { InitBolt(); }
// ША K8   // конструктор - для состовного объекта
// ША K8   Bolt7801( short _type, char** pBuf, BaseMakroParam* _par );
// ША K8   virtual int   Size() { return ConstrObject::Size() + 52; }
// ША K8   Bolt7801*     Dublicate();                    // оператор копирования
// ША K8   virtual ConstrObject* DublicateObj();
// ША K8 
// ША K8 protected:
// ША K8   virtual bool  IsSimpleModeAvaible() { return false; } // для составного элемента рисовать детали упрощенно
// ША K8   virtual void  ViewDraw();              // Рисует основной вид
// ША K8   virtual void  BottomDraw();            // рисует вид снизу
// ША K8   virtual void  SetSimpleMode( bool ) {} // для составного элемента рисовать детали упрощенно
// ША K8 };
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // конструктор - для состовного объекта
// ША K8 // ---
// ША K8 Bolt7801::Bolt7801( short _type, char** pBuf, BaseMakroParam* _par )
// ША K8   : BoltMain( 7801, _type, pBuf, _par ) {
// ША K8 //    !!! Внимание если появится версия то size должен быть посчитан с учетом версии !!!
// ША K8   if ( pBuf && *pBuf ) 
// ША K8     *pBuf = (char*)_par + Size(); // смещаем указатель на размер данных
// ША K8 }
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // конструктор копии
// ША K8 // ---
// ША K8 Bolt7801* Bolt7801::Dublicate() {
// ША K8   return new Bolt7801( *this );
// ША K8 }
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // конструктор копии
// ША K8 // ---
// ША K8 ConstrObject* Bolt7801::DublicateObj() {
// ША K8   return new Bolt7801( *this );
// ША K8 };
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // Рисует вид снизу
// ША K8 // ---
// ША K8 void Bolt7801::BottomDraw() {
// ША K8   TopDraw();                          // Головка
// ША K8 
// ША K8   int    kp1;                       // кол-во точек пересечения
// ША K8   double xp1, yp1;                  // координаты точки пересечения
// ША K8   ::IntersectHeadPin( bolt, kp1, xp1, yp1 );
// ША K8 
// ША K8   if ( kp1 ) {
// ША K8     int    kp;                                             // кол-во точек пересечения
// ША K8     double xp[2], yp[2];                                   // координаты точки пересечения
// ША K8 
// ША K8     float radThr = bolt.dr * 0.5;     // радиус резьбы
// ША K8     float heigth = yp1 - radThr;
// ША K8     // пересечение стержня и боковой грани уса
// ША K8     ::IntersectCirLin( 0, 0,                    radThr,    // окружность
// ША K8                        0, - yp1 + heigth * 0.5, 0,         // прямая
// ША K8                        &kp, xp, yp );                      // возвращаемые значения
// ША K8     if ( kp == 2 ) {
// ША K8 
// ША K8       ::BoltBarBottomDraw( bolt );        // стержень
// ША K8 
// ША K8       yp1 = - (radThr - heigth);          // ус
// ША K8       ::LineSeg( 0, yp1, xp[0], yp[0],    BASE_LINE );
// ША K8       ::LineSeg( 0, yp1, xp[1], yp[1],    BASE_LINE );
// ША K8       ::LineSeg( 0, yp1, 0,     - radThr, BASE_LINE );
// ША K8     }
// ША K8   }
// ША K8 }
// ША K8 
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // Рисование оконтовки головки для болтов 7801 и 7783
// ША K8 // ---
// ША K8 void SideHead( float x, float y, float my ) {
// ША K8   ::LineSeg( x, y,  x, my, BASE_LINE );
// ША K8   ::LineSeg( x, my, 0, my, BASE_LINE );
// ША K8   ::LineSeg( 0, my, 0, y,  BASE_LINE );
// ША K8   ::LineSeg( 0, y,  x, y,  BASE_LINE );
// ША K8 }
// ША K8 
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // Рисование основного вида болта
// ША K8 // ---
// ША K8 void Bolt7801::ViewDraw() {
// ША K8   int    kp;                                                   // кол-во точек пересечения
// ША K8   double xp[2], yp[2];                                         // координаты точки пересечения
// ША K8   ::IntersectHead( bolt, kp, xp, yp );                         // пересечение сферы и оконтовки головки
// ША K8 
// ША K8   if ( kp != 0 ) {                                             // Головка
// ША K8     float xCenter = bolt.param2 - bolt.k;                      // координата х центра сферы
// ША K8     ::ArcByPoint( xCenter/*x центра*/,   0/*y центра*/,           bolt.param2/*радиус*/,
// ША K8                   xp[0]/*x нач. точки*/, yp[0]/*y нач. точки*/,
// ША K8                   xp[0]/*x кон. точки*/, - yp[0]/*y кон. точки*/,
// ША K8                   1/*направление*/,      BASE_LINE );
// ША K8 
// ША K8     // края головки
// ША K8     ::SideHead( xp[0], yp[0], - yp[0] );
// ША K8 
// ША K8     if ( !(bolt.f & DRAW_ST_OF) ) {     // Рисовать стержень?
// ША K8 
// ША K8       int    kp1;                       // кол-во точек пересечения
// ША K8       double xp1, yp1;                  // координаты точки пересечения
// ША K8 
// ША K8       ::IntersectHeadPin( bolt, kp1, xp1, yp1 );
// ША K8 
// ША K8       if ( kp1 ) {
// ША K8         float radThr  = bolt.dr * 0.5;    // радиус резьбы
// ША K8         float yCenter = radThr + bolt.rp; // у центра окружности под головкой
// ША K8         ::ArcByPoint( bolt.rp/*x центра*/,     yCenter/*y центра*/,     bolt.rp/*радиус*/,
// ША K8                       0/*x нач. точки*/,       yCenter/*y нач. точки*/,
// ША K8                       bolt.rp/*x кон. точки*/, radThr/*y кон. точки*/,
// ША K8                       1/*направление*/,        BASE_LINE ); // радиус под головкой
// ША K8 
// ША K8         ::BoltBarThrDraw( bolt );
// ША K8         float lengthBar = bolt.l - bolt.z4;      // длина стержня без фаски
// ША K8         ::LineSeg( bolt.rp, radThr, lengthBar, radThr, BASE_LINE ); // стержень без фаски вверху
// ША K8 
// ША K8         float mRadThr = - radThr;
// ША K8         ::LineSeg( bolt.param1, mRadThr, lengthBar, mRadThr, BASE_LINE ); // стержень без фаски внизу
// ША K8 
// ША K8         float heigth = yp1 - radThr;
// ША K8         // ус
// ША K8         ::LineSeg( 0,           - yp1 + heigth * 0.5,   bolt.param1, mRadThr,          BASE_LINE );
// ША K8         ::LineSeg( bolt.param1, mRadThr,                0,           mRadThr + heigth, BASE_LINE );
// ША K8       }
// ША K8     }
// ША K8     ::BoltAxisDraw( bolt );
// ША K8   }
// ША K8 }
// ША K8 
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // пересечение стержня и боковой грани уса 7783, 7785
// ША K8 // ---
// ША K8 void IntersectBarPin( const BoltMainStruct &bolt,
// ША K8                       int &kp, double xp[], double yp[] ) {
// ША K8 
// ША K8     float xCoor  = bolt.v * 0.5;           // координата х вершины уса
// ША K8     float radThr = bolt.dr * 0.5;          // радиус резьбы
// ША K8     float yCoor  = - radThr - bolt.param1; // координата y вершины уса
// ША K8 
// ША K8     ::IntersectCirLin( 0,     0,     radThr,     // окружность
// ША K8                        xCoor, yCoor, 90,         // прямая
// ША K8                        &kp,   xp,    yp );       // возвращаемые значения
// ША K8 }
// ША K8 
// ША K8 
// ША K8 
// ША K8 ////////////////////////////////////////////////////////////////////////////////
// ША K8 //
// ША K8 // Класс Bolt7783
// ША K8 // Болт ГОСТ 7783-81
// ША K8 //
// ША K8 ////////////////////////////////////////////////////////////////////////////////
// ША K8 class Bolt7783  : public BoltMain {
// ША K8 public:
// ША K8   Bolt7783() : BoltMain( 7783 ) { InitBolt(); }
// ША K8   // конструктор - для состовного объекта
// ША K8   Bolt7783( short _type, char** pBuf, BaseMakroParam* _par );
// ША K8   virtual int   Size() { return ConstrObject::Size() + sizeof(bolt) - sizeof(float); }
// ША K8   Bolt7783*     Dublicate();                    // оператор копирования
// ША K8   virtual ConstrObject* DublicateObj();
// ША K8 
// ША K8 protected:
// ША K8   virtual bool  IsSimpleModeAvaible() { return false; } // для составного элемента рисовать детали упрощенно
// ША K8   virtual void  ViewDraw();              // Рисует основной вид
// ША K8   virtual void  BottomDraw();            // рисует вид снизу
// ША K8   virtual void  SetSimpleMode( bool ) {} // для составного элемента рисовать детали упрощенно
// ША K8 };
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // конструктор - для состовного объекта
// ША K8 // ---
// ША K8 Bolt7783::Bolt7783( short _type, char** pBuf, BaseMakroParam* _par )
// ША K8   : BoltMain( 7783, _type, pBuf, _par ) {
// ША K8 //    !!! Внимание если появится версия то size должен быть посчитан с учетом версии !!!
// ША K8   if ( pBuf && *pBuf )
// ША K8     *pBuf = (char*)_par + Size(); // смещаем указатель на размер данных
// ША K8 }
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // конструктор копии
// ША K8 // ---
// ША K8 Bolt7783* Bolt7783::Dublicate() {
// ША K8   return new Bolt7783( *this );
// ША K8 }
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // конструктор копии
// ША K8 // ---
// ША K8 ConstrObject* Bolt7783::DublicateObj() {
// ША K8   return new Bolt7783( *this );
// ША K8 };
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // Рисует вид снизу
// ША K8 // ---
// ША K8 void Bolt7783::BottomDraw() {
// ША K8   TopDraw();                          // Головка
// ША K8 
// ША K8   int    kp;                             // кол-во точек пересечения
// ША K8   double xp[2], yp[2];                   // координаты точки пересечения
// ША K8   ::IntersectBarPin( bolt, kp, xp, yp ); // пересечение стержня и боковой грани уса
// ША K8 
// ША K8   if ( kp ) {
// ША K8     ::BoltBarBottomDraw( bolt );        // стержень
// ША K8 
// ША K8     float xCoor = bolt.v * 0.5;                  // координата х вершины уса
// ША K8     float yCoor = - bolt.dr * 0.5 - bolt.param1; // координата y вершины уса
// ША K8 
// ША K8     // ус
// ША K8     ::LineSeg( - xCoor, yCoor, xCoor,   yCoor, BASE_LINE );
// ША K8     ::LineSeg( - xCoor, yCoor, - xp[1], yp[1], BASE_LINE );
// ША K8     ::LineSeg( xCoor,   yCoor, xp[1],   yp[1], BASE_LINE );
// ША K8   }
// ША K8 }
// ША K8 
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // Рисование основного вида болта
// ША K8 // ---
// ША K8 void Bolt7783::ViewDraw() {
// ША K8 
// ША K8   float radHead = bolt.d * 0.5;                                // радиус головки
// ША K8   ::ArcBy3Points( - 1/*x нач. точки*/,        radHead/*y нач. точки*/,
// ША K8                   - bolt.k/*x средн. точки*/, 0/*y средн. точки*/,
// ША K8                   - 1/*x кон. точки*/,        - radHead/*y кон. точки*/,
// ША K8                   BASE_LINE );
// ША K8 
// ША K8   // края головки
// ША K8   ::SideHead( - 1, radHead, - radHead );
// ША K8 
// ША K8   if ( !(bolt.f & DRAW_ST_OF) ) {     // Рисовать стержень?
// ША K8 
// ША K8     int    kp;                             // кол-во точек пересечения
// ША K8     double xp[2], yp[2];                   // координаты точки пересечения
// ША K8     ::IntersectBarPin( bolt, kp, xp, yp ); // пересечение стержня и боковой грани уса
// ША K8 
// ША K8     float radThr = bolt.dr * 0.5;          // радиус резьбы
// ША K8     float yCoor  = - radThr - bolt.param1; // координата y вершины уса
// ША K8 
// ША K8     int    kp2;                        // кол-во точек пересечения
// ША K8     double xp2, yp2;                   // координаты точки пересечения
// ША K8     // пересечение верхней и нижней граней уса (основной вид)
// ША K8     ::IntersectLinLin( 0/*коор-та x*/, yp[1]/*коор-та у*/, 0/*угол*/,  // первая линия
// ША K8                        0/*коор-та x*/, yCoor/*коор-та у*/, 30/*угол*/, // вторая линия
// ША K8                        &kp2, &xp2, &yp2 );                             // возвращяемые значения
// ША K8 
// ША K8     int    kp1;                       // кол-во точек пересечения
// ША K8     double xp1, yp1;                  // координаты точки пересечения
// ША K8     // пересечение нижней грани уса и стержня ( основной вид )
// ША K8     ::IntersectLinLin( 0/*коор-та x*/, - radThr/*коор-та у*/, 0/*угол*/,  // первая линия
// ША K8                        0/*коор-та x*/, yCoor/*коор-та у*/,    30/*угол*/, // вторая линия
// ША K8                        &kp1, &xp1, &yp1 );                                // возвращяемые значения
// ША K8 
// ША K8     if ( kp && kp1 && kp2 ) {
// ША K8       float yCenter = radThr + bolt.rp; // у центра окружности под головкой
// ША K8       ::ArcByPoint( bolt.rp/*x центра*/,     yCenter/*y центра*/,     bolt.rp/*радиус*/,
// ША K8                     0/*x нач. точки*/,       yCenter/*y нач. точки*/,
// ША K8                     bolt.rp/*x кон. точки*/, radThr/*y кон. точки*/,
// ША K8                     1/*направление*/,        BASE_LINE );
// ША K8 
// ША K8       // ус
// ША K8       ::LineSeg( 0,   yp[1], xp2, yp2,   BASE_LINE );
// ША K8       ::LineSeg( xp2, yp2,   0,   yCoor, BASE_LINE );
// ША K8 
// ША K8       // если резьба до уса (kr = 0) и длина подголовка меньше длины уса,
// ША K8       // то увеличиваем длину подголовка до длины уса (уменьшаем длину резьбы)
// ША K8       if ( (bolt.h < xp2) && (bolt.kr == 0) )
// ША K8         bolt.b =  bolt.l - xp2;
// ША K8       ::BoltBarThrDraw( bolt );                // стержень
// ША K8 
// ША K8       float lengthBar = bolt.l - bolt.z4;      // длина стержня без фаски
// ША K8       float endThr    = bolt.l - bolt.b;       // координата конца резьбы
// ША K8 
// ША K8       if ( (bolt.perf == 2) && (bolt.kr == 1) ) {
// ША K8         // если длина подголовка меньше длины уса увеличиваем длину подголовка
// ША K8         float heigth = bolt.h > xp2 ? bolt.h : xp2 + 1;
// ША K8         ::LineSeg( bolt.rp, radThr,   heigth,    radThr,   BASE_LINE ); // верхняя грань подголовка
// ША K8         ::LineSeg( xp1,     yp1,      heigth,    - radThr, BASE_LINE ); // нижняя грань подголовка
// ША K8 
// ША K8         short sign = 1;
// ША K8         for ( int i = 1; i <= 2; i++ ) {
// ША K8           float mRadThr = sign * radThr;
// ША K8           float radOnBar = bolt.p * 0.5;
// ША K8           float rD2 = sign * (radThr - radOnBar);
// ША K8           float xCenter = heigth + radOnBar;    // скругления на стрержне под подголовком
// ША K8           ::ArcByPoint( xCenter/*x центра*/,     mRadThr/*y центра*/,     radOnBar/*радиус*/,
// ША K8                         heigth/*x нач. точки*/,  mRadThr/*y нач. точки*/,
// ША K8                         xCenter/*x кон. точки*/, rD2/*y кон. точки*/,
// ША K8                         sign/*направление*/,        BASE_LINE );
// ША K8 
// ША K8           float xCenter1 = endThr - radOnBar;   // скругления на стрержне около части с резьбой
// ША K8           ::ArcByPoint( xCenter1/*x центра*/,     mRadThr/*y центра*/,      radOnBar/*радиус*/,
// ША K8                         endThr/*x нач. точки*/,   mRadThr/*y нач. точки*/,
// ША K8                         xCenter1/*x кон. точки*/, rD2/*y кон. точки*/,
// ША K8                         (short) - sign/*направление*/,       BASE_LINE );
// ША K8 
// ША K8           ::LineSeg( endThr,   mRadThr, lengthBar, mRadThr, BASE_LINE ); // стержень без фаски
// ША K8           ::LineSeg( xCenter1, rD2,     xCenter,   rD2,     BASE_LINE ); // стержень от подголовка до резьбы
// ША K8 
// ША K8           sign *= (short) -1;
// ША K8         }
// ША K8 
// ША K8         ::LineSeg( heigth, radThr, heigth, - radThr, BASE_LINE ); // граница подголовка
// ША K8       }
// ША K8       else {
// ША K8         ::LineSeg( bolt.rp, radThr, lengthBar, radThr,   BASE_LINE ); // стержень без фаски вверху
// ША K8         ::LineSeg( xp1,     yp1,    lengthBar, - radThr, BASE_LINE ); // стержень без фаски внизу
// ША K8       }
// ША K8     }
// ША K8   }
// ША K8   ::BoltAxisDraw( bolt );
// ША K8 }
// ША K8 
// ША K8 
// ША K8 
// ША K8 ////////////////////////////////////////////////////////////////////////////////
// ША K8 //
// ША K8 // Класс Bolt7785
// ША K8 // Болт ГОСТ 7785-81
// ША K8 //
// ША K8 ////////////////////////////////////////////////////////////////////////////////
// ША K8 class Bolt7785  : public BoltMain {
// ША K8 public:
// ША K8   Bolt7785() : BoltMain( 7785 ) { InitBolt(); }
// ША K8   // конструктор - для состовного объекта
// ША K8   Bolt7785( short _type, char** pBuf, BaseMakroParam* _par );
// ША K8 
// ША K8   virtual int   Size() { return ConstrObject::Size() + 56; }
// ША K8   Bolt7785*     Dublicate();                    // оператор копирования
// ША K8   virtual ConstrObject* DublicateObj();
// ША K8 
// ША K8 protected:
// ША K8   virtual bool  IsSimpleModeAvaible() { return false; } // для составного элемента рисовать детали упрощенно
// ША K8   virtual void  BottomDraw();                  // рисует вид снизу
// ША K8   virtual void  ViewHalfDraw( bool downHalf ); // Рисует половину основного вида
// ША K8   virtual void  ViewDraw();                    // Рисует основной вид
// ША K8 };
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // конструктор - для состовного объекта
// ША K8 // ---
// ША K8 Bolt7785::Bolt7785( short _type, char** pBuf, BaseMakroParam* _par )
// ША K8   : BoltMain( 7785, _type, pBuf, _par ) {
// ША K8 //    !!! Внимание если появится версия то size должен быть посчитан с учетом версии !!!
// ША K8   if ( pBuf && *pBuf )
// ША K8     *pBuf = (char*)_par + Size(); // смещаем указатель на размер данных
// ША K8 }
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // конструктор копии
// ША K8 // ---
// ША K8 Bolt7785* Bolt7785::Dublicate() {
// ША K8   return new Bolt7785( *this );
// ША K8 }
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // конструктор копии
// ША K8 // ---
// ША K8 ConstrObject* Bolt7785::DublicateObj() {
// ША K8   return new Bolt7785( *this );
// ША K8 };
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // Рисует вид снизу
// ША K8 // ---
// ША K8 void Bolt7785::BottomDraw() {
// ША K8   TopDraw();                                  // Головка
// ША K8 
// ША K8   if ( !(bolt.f & DRAW_ST_OF) ) {             // Рисовать стержень?
// ША K8 
// ША K8     float xCoor  = bolt.v * 0.5;              // координата х вершины уса
// ША K8     float radThr = bolt.dr * 0.5;             // радиус резьбы
// ША K8     float yCoor  = - radThr - bolt.param1;    // координата y вершины уса
// ША K8 
// ША K8     int    kp;                                // кол-во точек пересечения
// ША K8     double xp[2], yp[2];                      // координаты точки пересечения
// ША K8     ::IntersectBarPin( bolt, kp, xp, yp );    // пересечение стержня и боковой грани уса
// ША K8 
// ША K8     int    kp1;                               // кол-во точек пересечения
// ША K8     double xp1[2], yp1[2];                    // координаты точки пересечения
// ША K8 
// ША K8     float radHead = bolt.d * 0.5;             // радиус головки
// ША K8     ::IntersectCirLin( 0,     0,     radHead, // окружность
// ША K8                        xCoor, yCoor, 90,      // прямая
// ША K8                        &kp1,  xp1,   yp1 );   // возвращаемые значения
// ША K8 
// ША K8     if ( kp ) {
// ША K8       ::BoltBarBottomDraw( bolt );            // стержень
// ША K8 
// ША K8       // ус
// ША K8       ::LineSeg( - xCoor, yp1[1], - xp[1], yp[1], BASE_LINE );
// ША K8       ::LineSeg( xCoor,   yp1[1], xp[1],   yp[1], BASE_LINE );
// ША K8     }
// ША K8   }
// ША K8 }
// ША K8 
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // пересечение стержня и подголовка 7785
// ША K8 // ---
// ША K8 void IntersectBarHeadRest( const BoltMainStruct &bolt,
// ША K8                            int &kp, double &xp, double &yp ) {
// ША K8   float radThr  = (bolt.perf == 2) && bolt.kr
// ША K8                       ? bolt.dr * 0.5 - bolt.p * 0.5
// ША K8                       : bolt.dr * 0.5; // радиус резьбы
// ША K8   float radHead = bolt.d * 0.5;     // радиус головки
// ША K8   float angle = 180 - bolt.param2 * 0.5; // угол
// ША K8 
// ША K8   // пересечение стержня и подголовка
// ША K8   ::IntersectLinLin( 0/*коор-та x*/,   radThr/*коор-та у*/,  0/*угол*/,     // первая линия
// ША K8                      0.5/*коор-та x*/, radHead/*коор-та у*/, angle/*угол*/, // вторая линия
// ША K8                      &kp, &xp, &yp );                                     // возвращяемые значения
// ША K8 }
// ША K8 
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // Рисование основного вида болта
// ША K8 // ---
// ША K8 void Bolt7785::ViewDraw() {
// ША K8   ViewHalfDraw( false/*downHalf*/ );  // верхняя часть
// ША K8   ViewHalfDraw( true /*downHalf*/ );  // Нижняя часть
// ША K8 
// ША K8   int    kp;                          // кол-во точек пересечения
// ША K8   double xp, yp;                      // координаты точки пересечения
// ША K8   ::IntersectBarHeadRest( bolt, kp, xp, yp ); // пересечение стержня и подголовка
// ША K8 
// ША K8   float yCoor  = - bolt.d * 0.5;
// ША K8   float radThr = (bolt.perf == 2) && bolt.kr ? bolt.dr * 0.5 - bolt.p * 0.5
// ША K8                                              : bolt.dr * 0.5;            // радиус резьбы
// ША K8 
// ША K8   // пересечение граней уса
// ША K8   int    kp1;                         // кол-во точек пересечения
// ША K8   double xp1, yp1;                    // координаты точки пересечения
// ША K8   ::IntersectLinLin( xp/*коор-та x*/,   - radThr/*коор-та у*/, 75/*угол*/, // первая линия
// ША K8                      0.5/*коор-та x*/,  yCoor/*коор-та у*/,    5/*угол*/,  // вторая линия
// ША K8                      &kp1,              &xp1,                  &yp1 );     // возвращяемые значения
// ША K8   if ( kp && kp1 ) {
// ША K8     // изображение уса
// ША K8     if ( (bolt.perf == 2) && bolt.kr ) {
// ША K8       ::LineSeg( 0.5, yCoor, xp1, yp1,      BASE_LINE );
// ША K8       ::LineSeg( xp1, yp1,   xp,  - radThr, BASE_LINE );
// ША K8     }
// ША K8     else {
// ША K8       ::LineSeg( 0.5, yCoor, xp1, yp1,      BASE_LINE );
// ША K8       ::LineSeg( xp1, yp1,   xp,  - radThr, BASE_LINE );
// ША K8     }
// ША K8   }
// ША K8   if ( !(bolt.f & AXIS_OFF) )         // оси
// ША K8     ::LineSeg( - AXIS_END, 0, bolt.l + AXIS_END, 0, AXIS_LINE );
// ША K8 
// ША K8 }
// ША K8 
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // Рисование половины основного вида болта:
// ША K8 // downHalf = false - верхняя часть, true - нижняя
// ША K8 // ---
// ША K8 void Bolt7785::ViewHalfDraw( bool downHalf ) {
// ША K8   int sign = downHalf ? -1 : 1;
// ША K8 
// ША K8   int    kp1;                       // кол-во точек пересечения
// ША K8   double xp1, yp1;                  // координаты точки пересечения
// ША K8   ::IntersectBarHeadRest( bolt, kp1, xp1, yp1 ); // пересечение стержня и подголовка
// ША K8 
// ША K8   if ( kp1 ) {
// ША K8     float radThr  = bolt.dr * 0.5;       // радиус резьбы
// ША K8     float d2      = bolt.p * 0.5;
// ША K8     float radD2   = radThr - d2;         // радиус cтержня
// ША K8     float radHead = sign * bolt.d * 0.5;                 // радиус головки
// ША K8 
// ША K8     float yCoor   = (bolt.perf == 2) && bolt.kr ? sign * radD2 : sign * radThr;
// ША K8     ::LineSeg( 0.5, radHead, xp1, yCoor, BASE_LINE );    // подголовок
// ША K8     ::LineSeg( xp1, yCoor,   xp1, 0,     BASE_LINE );    // граница подголовка
// ША K8 
// ША K8     radThr *= sign;                                      // радиус резьбы
// ША K8     ::HalfSideHead( 0.5/*ширина оконтовки*/, radHead );  // оконтовка головки
// ША K8 
// ША K8     float endThr = bolt.kr ? bolt.l - bolt.b : xp1;               // координата конца резьбы
// ША K8     if ( bolt.kr )
// ША K8       ::LineSeg( endThr, radThr, endThr, 0, BASE_LINE );          // граница резьбы
// ША K8 
// ША K8     float pThread = radThr - sign * MODSTEP_REAL * bolt.p;                       // координата у линии обозначения резьбы
// ША K8     int kp;
// ША K8     double xp, yp;
// ША K8     ::IntersectFaceThread( bolt, kp, xp, yp );
// ША K8 
// ША K8     if ( kp )
// ША K8       ::LineSeg( endThr, pThread, xp, pThread, SLIM_LINE );       // обозначение резьбы
// ША K8 
// ША K8     float lengthBar = bolt.l - bolt.z4;                           // длина стержня без фаски
// ША K8     float radDp     = sign * bolt.dp * 0.5;                       // радиус резьбы без фаски
// ША K8     ::LineSeg( lengthBar, radThr, bolt.l, radDp, BASE_LINE );     // фаска
// ША K8     ::LineSeg( bolt.l,    radDp,  bolt.l, 0,     BASE_LINE );     // конец болта
// ША K8 
// ША K8     ::LineSeg( lengthBar, radThr, lengthBar, 0,  BASE_LINE );     // конец стержня без фаски
// ША K8 
// ША K8     if ( (bolt.perf == 1) || !bolt.kr )
// ША K8       ::LineSeg( xp1, radThr, lengthBar, radThr, BASE_LINE );     // стержень без фаски
// ША K8     else {
// ША K8       radD2         *= sign;
// ША K8       float xCenter1 = endThr - d2;
// ША K8       // скругление около границы резьбы
// ША K8       ::ArcByPoint( xCenter1/*x центра*/,     radThr/*y центра*/,     d2/*радиус*/,
// ША K8                     endThr/*x нач. точки*/,   radThr/*y нач. точки*/,
// ША K8                     xCenter1/*x кон. точки*/, radD2/*y кон. точки*/,
// ША K8                     (short) - sign/*направление*/,    BASE_LINE );
// ША K8 
// ША K8       ::LineSeg( xp1,    radD2,  xCenter1,  radD2,  BASE_LINE ); // стержень от подголовка до границы резьбы
// ША K8       ::LineSeg( endThr, radThr, lengthBar, radThr, BASE_LINE ); // стержень
// ША K8     }
// ША K8   }
// ША K8 }



//------------------------------------------------------------------------------
// Создание экземпляра, вызов конструктора класса болта по госту и возврат указателя
// на него. Болт ГОСТ 7787-81
// ---
// RA CPar * NewBolt7787( short _type, char** pBuf, BaseMacroParam* _par ) {
// RA // ША K8   if ( _type )
// RA // ША K8     return new BoltMain( 7787, _type, pBuf, _par );
// RA // ША K8   else
// RA     return new BoltMain( 7787 );
// RA }


//------------------------------------------------------------------------------
// Создание экземпляра, вызов конструктора класса болта по госту и возврат указателя
// на него. Болт ГОСТ 7787-81
// ---
CPar * NewBolt7787( reference obj, bool fromDataBase ) {
    return new BoltMain( obj, fromDataBase );
}

// ША K8 //------------------------------------------------------------------------------
// ША K8 // Создание экземпляра, вызов конструктора класса болта по госту и возврат указателя
// ША K8 // на него. Болт ГОСТ 7783-81
// ША K8 // ---
// ША K8 ConstrObject * NewBolt7783( short _type, char** pBuf, BaseMakroParam* _par ) {
// ША K8   if ( _type )
// ША K8     return new Bolt7783( _type, pBuf, _par );
// ША K8   else
// ША K8     return new Bolt7783();
// ША K8 }
// ША K8 
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // Создание экземпляра, вызов конструктора класса болта по госту и возврат указателя
// ША K8 // на него. Болт ГОСТ 7785-81
// ША K8 // ---
// ША K8 ConstrObject * NewBolt7785( short _type, char** pBuf, BaseMakroParam* _par ) {
// ША K8   if ( _type )
// ША K8     return new Bolt7785( _type, pBuf, _par );
// ША K8   else
// ША K8     return new Bolt7785();
// ША K8 }
// ША K8 
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // Создание экземпляра, вызов конструктора класса болта по госту и возврат указателя
// ША K8 // на него. Болт ГОСТ 7801-81
// ША K8 // ---
// ША K8 ConstrObject * NewBolt7801( short _type, char** pBuf, BaseMakroParam* _par ) {
// ША K8   if ( _type )
// ША K8     return new Bolt7801( _type, pBuf, _par );
// ША K8   else
// ША K8     return new Bolt7801();
// ША K8 }
// ША K8 
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // Создание экземпляра, вызов конструктора класса Bolt7802 и возврат указателя
// ША K8 // на него.
// ША K8 // ---
// ША K8 ConstrObject * NewBolt7802( short _type, char** pBuf, BaseMakroParam* _par ) {
// ША K8   if ( _type )
// ША K8     return new Bolt7802( _type, pBuf, _par );
// ША K8   else
// ША K8     return new Bolt7802();
// ША K8 }
// ША K8 
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // Создание экземпляра, вызов конструктора класса болта по госту и возврат указателя
// ША K8 // на него. Болт ГОСТ 7786-81
// ША K8 // ---
// ША K8 ConstrObject * NewBolt7786( short _type, char** pBuf, BaseMakroParam* _par ) {
// ША K8   if ( _type )
// ША K8     return new Bolt7786( 7786, _type, pBuf, _par );
// ША K8   else
// ША K8     return new Bolt7786( 7786 );
// ША K8 }
// ША K8 
// ША K8 
// ША K8 
// ША K8 //------------------------------------------------------------------------------
// ША K8 // Создание экземпляра, вызов конструктора класса болта по госту и возврат указателя
// ША K8 // на него. Болт ГОСТ 17673-81
// ША K8 // ---
// ША K8 ConstrObject * NewBolt17673( short _type, char** pBuf, BaseMakroParam* _par ) {
// ША K8   if ( _type )
// ША K8     return new Bolt7786( 17673, _type, pBuf, _par );
// ША K8   else
// ША K8     return new Bolt7786( 17673 );
// ША K8 }
// ША K8 
