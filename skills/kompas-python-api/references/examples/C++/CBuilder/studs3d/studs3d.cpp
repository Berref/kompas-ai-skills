////////////////////////////////////////////////////////////////////////////////
//
// studs3d.cpp - Крепежный элемент на Visual C++ - шпилька
//
////////////////////////////////////////////////////////////////////////////////
#ifndef VCL_H
#include <vcl.h>
#endif

#ifndef __WINDOWS_
#include <windows.h>
#endif

#ifndef __STDIO_H
#include <stdio.h>
#endif

#ifndef  __MATH_H
#include <math.h>
#endif

#pragma hdrstop

#include <objbase.h>
#include <initguid.h>

#ifndef __LIBHPPAR_H
#include "libhppar.h"
#endif

#ifndef __STUDS3D_RH
#include "studs3D.rh"
#endif

#ifndef __STUDS3D_H
#include "studs3D.h"
#endif

#include "ksConstants.h"

#if !defined(_IFUNC)
# define _IFUNC STDMETHODCALLTYPE
#endif

HINSTANCE _hinst;

//------------------------------------------------------------------------------
// в Win32 линкуется SDK/lib/kAPI2D5bc.lib и kAPI3D5bc.lib
// в x64 линкуется SDK/lib64/kAPI2D5bc.a и kAPI3D5bc.a
// ---
#pragma comment(lib, "kAPI2D5bc")
#pragma comment(lib, "kAPI3D5bc")

//-------------------------------------------------------------------------------
// Глобальная переменная
// ---
Shpeel* obj;
static reference spcObj;


//------------------------------------------------------------------------------
// Загрузить строку из ресурса
// ---
LPTSTR _LoadStr( int id )
{ 
  static char buf[512]; 
  // Конвертировать строку в соответствии с текущим словарем
  ksConvertLangStrEx( _hinst, id, buf, 512 );
  return buf;
}


//-------------------------------------------------------------------------------
// Задать идентификатор ресурсов
// ---
extern "C" unsigned int far __export __stdcall LIBRARYID()
{
  return IDR_LIBID;
}


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
extern "C" void far __export __stdcall LIBRARYENTRY( unsigned int )
{
  Kompas6api3d5com_tlb::IDocument3DPtr pDocument3d( ksGetActive3dDocument(), false/*AddRef*/ ); // Получить указатель на активный документ трехмерной модели
  if ( (bool)pDocument3d && !pDocument3d->IsDetail() )
  {
    Shpeel* shpeel = new Shpeel();
    if ( shpeel ) 
    {
      shpeel->Draw3D( pDocument3d );
      delete shpeel;
    }
  }
  else
  {
    // Документ не активизирован или не является 3D-моделью
    Error( _LoadStr( STR_3DDOCERROR ) ); // Выдать сообщение о ошибке
  }

  if ( ReturnResult() == etError10 ) // Вырожденный объект
    ResultNULL();
}


////////////////////////////////////////////////////////////////////////////////
//
// Внекласные функции
//
////////////////////////////////////////////////////////////////////////////////


//------------------------------------------------------------------------------
// Строка по ГОСТу (Файлы *.loa)
// ---
static void NumberGost( int gost, int *gNumb, int *stNumb )
{
  switch ( gost ) 
  {
    case 22032 : *gNumb = STR_200; *stNumb = STR_220; break;
    case 22033 : *gNumb = STR_201; *stNumb = STR_221; break;
    case 22034 : *gNumb = STR_202; *stNumb = STR_222; break;
    case 22035 : *gNumb = STR_203; *stNumb = STR_223; break;
    case 22036 : *gNumb = STR_204; *stNumb = STR_224; break;
    case 22037 : *gNumb = STR_205; *stNumb = STR_225; break;
    case 22038 : *gNumb = STR_206; *stNumb = STR_226; break;
    case 22039 : *gNumb = STR_207; *stNumb = STR_227; break;
    case 22040 : *gNumb = STR_208; *stNumb = STR_228; break;
    case 22041 : *gNumb = STR_209; *stNumb = STR_229; break;
    case 22042 : *gNumb = STR_210; *stNumb = STR_230; break;
    case 22043 : *gNumb = STR_211; *stNumb = STR_231; break;
  }
}


//------------------------------------------------------------------------------
// Строка по ГОСТу (Название)
// ---
static int NumberStr( int gost ) 
{
  int n;
  switch ( gost ) 
  {
    case 22032 : n = STR59;	break;
    case 22033 : n = STR60;  break;
    case 22034 : n = STR61;  break;
    case 22035 : n = STR62;  break;
    case 22036 : n = STR63;  break;
    case 22037 : n = STR64;  break;
    case 22038 : n = STR65;  break;
    case 22039 : n = STR66;  break;
    case 22040 : n = STR67;  break;
    case 22041 : n = STR68;  break;
    case 22042 : n = STR69;  break;
    case 22043 : n = STR70;  break;
  }
  return n;
}


//-------------------------------------------------------------------------------
// Подключение к базе
// ---
int _ConnectDB( reference bd, char *name ) 
{
  static char fullName[512];
  bool res = false;
  if( GetModuleFileName( _hinst, fullName, sizeof(fullName) ) )
  {
    char *c = strrchr( fullName, '\\');
    if ( c ) 
    {
      *(c + 1) = '\0';
      strcat( fullName, name );
      OFSTRUCT ofs;
      if ( OpenFile(fullName, &ofs, OF_EXIST) != HFILE_ERROR )
        res = true;
      else 
      {
        *(c + 1) = '\0';
        strcat( fullName, "load\\" );
        strcat( fullName, name );
        if ( OpenFile(fullName , &ofs, OF_EXIST) != HFILE_ERROR )
          res = true;
      }
    }
  }
  return res ? ConnectDB( bd, fullName ) : ConnectDB( bd, name );
}


//------------------------------------------------------------------------------
// Присваивает переменной с именем varName значение val
// ---
void SetVarValue( Kompas6api3d5com_tlb::IVariableCollectionPtr & varArr, wchar_t * varName, double val )
{
  Kompas6api3d5com_tlb::IVariablePtr var( varArr->GetByName( varName, true, false), false/*AddRef*/ ); // Текущая переменная
  if ( var )
    var->SetValue( val ); // Сменить значение
}  


//------------------------------------------------------------------------------
// Определяет является ли объект поверхностью ( planar = true - плоскостью,
// planar = false - конической поверхностью )
// ---
bool IsSurface( Kompas6api3d5com_tlb::IEntityPtr & entity, bool planar = true )
{
  bool res = false;
  if ( entity )
  {
    IUnknownPtr defin( entity->GetDefinition(), false );
    Kompas6api3d5com_tlb::IFaceDefinitionPtr faceDef( defin );
    if ( faceDef )
    {
      if ( planar && faceDef->IsPlanar() )
        res = true;

      else if ( !planar && faceDef->IsCylinder() )
        res = true;
    }
  }
  return res;
} 


//------------------------------------------------------------------------------
// Определяет является ли объект осью
// ---
bool IsAxis( Kompas6api3d5com_tlb::IEntityPtr & entity )
{
  if ( entity ) 
  {
    return entity->IsIt( o3d_axis2Planes )        ||  // Ось по двум плоскостям
             entity->IsIt( o3d_axisOperation )    ||  // Ось операций
               entity->IsIt( o3d_axis2Points )    ||  // Ось по двум точкам
                 entity->IsIt( o3d_axisConeFace ) ||  // Ось конической поверхности
                   entity->IsIt( o3d_axisEdge );      // Ось по ребру
  }
  return false;
}
    

//------------------------------------------------------------------------------
// Добавить сопряжения
// ---
void AddMates( Shpeel& obj, Kompas6api3d5com_tlb::IDocument3DPtr & doc, Kompas6api3d5com_tlb::IEntityCollectionPtr & collection )
{
   Kompas6api3d5com_tlb::IEntityPtr entity( collection->GetByIndex(0), false/*AddRef*/ );
  if ( (bool)entity && IsSurface(entity) ) // Поверхность
    if ( !doc->AddMateConstraint(mc_Coincidence, entity, obj.GetEntityByName(L"Plane"), obj.GetDirectionElem(), 1, 0) )
    {
      collection->SetByIndex( NULL, 0 );
    }

  entity.Bind( collection->GetByIndex(1), false/*AddRef*/ );
  if ( (bool)entity && IsSurface(entity, false/*planar*/) ) // Коническая поверхность
    if ( !doc->AddMateConstraint(mc_Concentric, entity, obj.GetEntityByName(L"Axis"), 0, 1, 0) )
    {
      collection->SetByIndex( NULL, 1 );
    }

  entity.Bind( collection->GetByIndex(2), false/*AddRef*/ );
  if ( (bool)entity && IsAxis(entity) ) // Ось
    if ( !doc->AddMateConstraint(mc_Concentric, entity, obj.GetEntityByName(L"Axis"), 0, 1, 0) )
    {
      collection->SetByIndex( NULL, 2 );
    }
}

//------------------------------------------------------------------------------
// Удалить сопряжения
// ---
void DelMates( Shpeel& obj, Kompas6api3d5com_tlb::IDocument3DPtr & doc, Kompas6api3d5com_tlb::IEntityCollectionPtr & collection )
{
  Kompas6api3d5com_tlb::IEntityPtr entity( collection->GetByIndex(0), false/*AddRef*/ );
  if ( (bool)entity && IsSurface(entity) ) // Поверхность
    doc->RemoveMateConstraint( mc_Coincidence, entity, obj.GetEntityByName(L"Plane") );

  entity.Bind( collection->GetByIndex(1), false/*AddRef*/ );
  if ( (bool)entity && IsSurface(entity, false /*planar*/) ) // Коническая поверхность
    doc->RemoveMateConstraint( mc_Concentric, entity, obj.GetEntityByName(L"Axis") );

  entity.Bind( collection->GetByIndex(2), false/*AddRef*/ );
  if ( (bool)entity && IsAxis(entity) ) // Ось
    doc->RemoveMateConstraint( mc_Concentric, entity, obj.GetEntityByName(L"Axis") );
}


//------------------------------------------------------------------------------
// Чтение БД по диаметру
// ---
int Shpeel::ReadShpeelBase( float d )
{
  char buf[128];
  ::sprintf( buf, "t = 1 and d=%.1f", d );
  if ( !::Condition(bBase.bg,  bBase.rg2, buf) ) { return 0;}

  ShpeelTmp shpeelTmp;
  int rez = ::ReadRecord( bBase.bg, bBase.rg2, &shpeelTmp );
  if( rez )
  {
    tmp.d  = shpeelTmp.d;  // Диаметр резьбы
    tmp.p1 = shpeelTmp.p1; // Шаг резьбы
    tmp.p2 = shpeelTmp.p2; // Шаг резьбы
    tmp.b1 = shpeelTmp.b1; // Ввинчиваемый конец
    tmp.c  = shpeelTmp.c;  // Размер фаски
  }
  return  rez;
}


//------------------------------------------------------------------------------
// Читать параметры стержня
// Возвращает 1 - успех 0 - не найдено записи -1 - ошибка связи с БД
// ---
int Shpeel::ReadShpeelStBase()
{
  char buf[128];
  ::sprintf( buf, "t = 1 && L=%.1f & d=%.1f", tmp.l, tmp.d );
  if ( !::Condition(bBase.bs, bBase.rs2, buf) ) { return -1;}

  ShpeelSTmp shpeelSTmp;
  int i = ::ReadRecord( bBase.bs, bBase.rs2, &shpeelSTmp );
  if ( !i )  
  {
    ::sprintf( buf, "t = 1 and d=%.1f", tmp.d);
    if ( !::Condition(bBase.bs,  bBase.rs2, buf) ) { return -1;}

    ::ReadRecord( bBase.bs, bBase.rs2, &shpeelSTmp );
  }

  tmp.l  = shpeelSTmp.l;
  tmp.b  = shpeelSTmp.b;
  tmp.m1 = shpeelSTmp.m1;
  tmp.m2 = shpeelSTmp.m2;
  if ( tmp.gost > 22041 )
  {
    if ( fabs(tmp.b) > 0.001 )
    {
      tmp.f &=~ ALLST;
    }
    else 
    {
      tmp.f |= ALLST;
    }
  } 
  return 1;
}


//------------------------------------------------------------------------------
// Открытие БД и построение отношений
// ---
int Shpeel::OpenBase()
{
  bBase.bg = ::CreateDB( "TXT_DB" );
  bBase.bs = ::CreateDB( "TXT_DB" );

  int gNumb, stNumb;
  ::NumberGost( tmp.gost, &gNumb, &stNumb );
  if( !_ConnectDB( bBase.bg, _LoadStr( gNumb ) ) ) // 22032.loa ..
   return 0;
  else 
  {
    if( !_ConnectDB( bBase.bs, _LoadStr( stNumb ) ) )  // st22032.loa ..
      return 0;
    else 
    {
      bBase.rg1 = ::Relation( bBase.bg );
        ::RInt  ("t");
        ::RChar( "d", 20, 0 );
      ::EndRelation();
      if ( !::DoStatement(bBase.bg, bBase.rg1, "1 2" ) ) 
        return 0;
      else 
      {
        bBase.rg2 = ::Relation( bBase.bg );
          ::RInt  ("t");
          ::RFloat("d");
          ::RFloat("");
          ::RFloat("");
          ::RFloat("");
          ::RFloat("");
        ::EndRelation();
        if ( !::DoStatement( bBase.bg, bBase.rg2, "") )
          return 0;
        else 
        {
          bBase.rs1 = ::Relation( bBase.bs );
            ::RInt ( "t" );
            ::RChar( "L",20,0 );
            ::RFloat( "d" );
          ::EndRelation();
          if ( !::DoStatement(bBase.bs, bBase.rs1, "1 2 3" ) )
            return 0;
          else 
          {
            bBase.rs2 = ::Relation( bBase.bs );
              ::RInt ("t");
              ::RFloat("L");
              ::RFloat("d");
              ::RFloat("");
              ::RFloat("");
              ::RFloat("");
            ::EndRelation();
            if ( !::DoStatement( bBase.bs, bBase.rs2, "") )
              return 0;
            else 
            {
              openBase = true;
              return 1;
            }
          }
        }
      }
    }
  }
}


//------------------------------------------------------------------------------
// Закрытие БД
// ---
void Shpeel::CloseBase()
{
  if ( bBase.bg )
    ::DeleteDB( bBase.bg );
  if ( bBase.bs )
    ::DeleteDB( bBase.bs );
  openBase = false;
}


//------------------------------------------------------------------------------
// Получить параметры
// ---
int Shpeel::GetParam() 
{
  return part ? part->GetUserParam( &par, Size() ) : 0;
}


//------------------------------------------------------------------------------
// Конструктор
// ---
Shpeel::Shpeel()
  : collectChanged( false )
  , openBase      ( false )
{
  par.flagAttr    = 1;
  par.typeSwitch  = 0;
  par.ang         = 0;
  par.drawType    = 0;

  ::memset( &bBase, 0, sizeof(ShpeelBase) );
  if( !GetParam() )
  {
    Init();
  }
  else
  {
    if ( !tmp.ver )
      tmp.ver = 1;
  }
}


//------------------------------------------------------------------------------
// Конструктор копий
// ---
Shpeel::Shpeel( const Shpeel& other )
  : collectChanged( false )
  , openBase      ( false )
{
  par.flagAttr    = 1;
  par.typeSwitch  = 0;
  par.ang         = 0;
  par.drawType    = 0;

  ::memcpy( &bBase, &other.bBase, sizeof(ShpeelBase) );
  Assign( other );
}


//------------------------------------------------------------------------------
// Конструктор копии
// ---
Shpeel* Shpeel::Dublicate()
{
  return new Shpeel( *this );
}


//------------------------------------------------------------------------------
//
// ---
void Shpeel::Assign( const Shpeel& other ) 
{
  part        = other.part;
  flagMode    = other.flagMode;
  par         = other.par;
  collect     = other.collect;

  ::memcpy( &tmp, &other.tmp, sizeof(SHPEEL) );
}


//------------------------------------------------------------------------------
// Инициализация
// ---
void Shpeel::Init()
{
  tmp.gost       = (unsigned short)22032;
  par.drawType   = ID_VID;
  par.ang        = 0;
  tmp.f          = 0;
  tmp.f         |= TAKEISPOLN;
  tmp.d          = 20;
  tmp.p1         = 2.5;
  tmp.p2         = 1.5;
  tmp.c          = 2.5;
  tmp.indexMassa = 0;
  tmp.ver        = 1;
  tmp.b1         = 20;
  tmp.klass      = 2; /*klass=B*/
  tmp.l          = 90;
  tmp.b          = 46;
  tmp.m1         = 245.9f;
  tmp.m2         = 228.9f;
}


//------------------------------------------------------------------------------
// При вставке из библиотеки моделей указывается полный путь к файлу библиотеки и путь внутри библиотеки моделей
// ---
String& Shpeel::SetFileName()
{
  static char fullName[512];
  bool res = false;
  if( GetModuleFileName( _hinst, fullName, sizeof(fullName) ) )
  {
    char *c = strrchr( fullName, '\\');
    if ( c ) 
    {
      *(c + 1) = '\0';
      strcat( fullName, STUDS_FILE );
      OFSTRUCT ofs;
      if ( OpenFile(fullName, &ofs, OF_EXIST) != HFILE_ERROR )
        res = true;
      else 
      {
        *(c + 1) = '\0';
        strcat( fullName, "model\\" );
        strcat( fullName, STUDS_FILE );
        if ( OpenFile(fullName , &ofs, OF_EXIST) != HFILE_ERROR )
          res = true;
      }
    }
  }

  if( res )
  {
    strcat( fullName, STUDS_INPUT_PATH );
    fileName = fullName;
  }
  
  return fileName;
}


//------------------------------------------------------------------------------
// Редактируем переменные
// ---
void Shpeel::SetParam() 
{
  // Редактируем внешние переменные
  if( part ) 
  {
    // Массив внешних переменных детали
    Kompas6api3d5com_tlb::IVariableCollectionPtr varArr( part->VariableCollection(), false/*AddRef*/ );
    if ( varArr )
    {
      float l, b1 = 0, b; // Условие резьбы на всю длину - b1=0
      l = tmp.b1 + tmp.l; // Длина всей шпильки
      b = tmp.b;
      float step = tmp.f & PITCH ? tmp.p1 : tmp.p2;
      if( fabs(tmp.b1) < 0.001 ) // ГОСТ 22042, ГОСТ 22043
      {
        if( fabs(tmp.b) > 0.001 )
          b1 = b;
      }
      else
      {
        b1 = tmp.b1;
        if ( fabs(tmp.b) < 0.001  )
          b = tmp.l - 0.5f * tmp.d - 2 * step;
      }

      // Основные параметры
      ::SetVarValue( varArr, L"d",      tmp.d                        ); // Диаметр резьбы
      float len = fabs(b1 - b) < 0.001 ? tmp.l - b1 : tmp.l;
      ::SetVarValue( varArr, L"l",      len                          ); // Длина шпильки
      ::SetVarValue( varArr, L"b1",     b1                           ); // Длина ввинчиваемого конца
      ::SetVarValue( varArr, L"c1",     tmp.c                        ); // Размер фаски на конце стержня
      if ( fabs(l - b1 - b) > 0.001 )
        ::SetVarValue( varArr, L"l1",   l - b1 - b                   ); // Длина гладкой части стержня
      ::SetVarValue( varArr, L"t",      (step * 0.866 * 3 / 8)       ); // Толщина удаляемого материала
      int perf2 = ( !(tmp.f & ISPOLN) ) || ( tmp.f & ALLST ) || ( fabs(l - b1 - b) < 0.001 ) ? 1 : 0;
      ::SetVarValue( varArr, L"cut1",   perf2                        ); // Вкл/выкл исполнение 2
      ::SetVarValue( varArr, L"f1",     !(tmp.f & SIMPLE) ? 0.0 /*Вкл*/ : 1.0 /*Выкл*/ ); // Вкл/выкл подголовок

      // Задать название детали
      char buf[255];
      ::sprintf( buf, _LoadStr( STR_STUD_NAME ), tmp.d, tmp.l, tmp.gost ); // создать имя детали
      WideString wstr(buf);
      part->SetName( wstr.c_bstr() ); // Присвоить детали новое имя
      part->_Update();        // Обновить деталь

      // Перестроим модель с измененными внешними переменными
      part->RebuildModel();
    }

    part->SetUserParam( &par, Size(), 0, 0, -1 );
  }
}


//------------------------------------------------------------------------------
// Выбор меню
// ---
int Shpeel::ChoiceMenuId() 
{

  switch ( par.drawType )
  {
    case ID_VID    : // Вид
      return  !par.typeSwitch ?  MENU_22032_1 : MENU_22032_3;
    case ID_TOPVID : // Вид сверху
      return  !par.typeSwitch ?  MENU_22032_2 : MENU_22032_4;
  }

  return 0;
}


//------------------------------------------------------------------------------
// Редактирование объекта спецификации
// ---
reference Shpeel::EditSpcObj( reference spcObj )
{
  Kompas6api3d5com_tlb::ISpecification3DPtr specification( doc->GetSpecification(), false/*AddRef*/ );
  if ( !flagMode && !par.flagAttr && !specification )
    return 0;

  if ( flagMode )
  {
    spcObj = specification->GetSpcObjForGeomWithLimit( NULL,             // Имя библиотеки типов
                                                       0,                // Номер типа спецификации
                                                       part,
                                                       1,                // 1 - первый объект 0- следующий объект
                                                       STANDART_SECTION, // Номер раздела
                                                       81764182256.0 );
    if( !par.flagAttr )
      return spcObj;


    if ( spcObj && !::ksSpcObjectEdit( spcObj ) )
      spcObj = 0;
  }
  bool flagMode = !!spcObj;
  if ( flagMode || ksSpcObjectCreate( NULL,                 // Имя библиотеки типов
                                      0,                    // Номер типа спецификации
                                      STANDART_SECTION, 0,  // Номер раздела и подраздела
                                      81764182256.0, 0) )   // Тип атрибута
  {
    // Исполнение
    UINT uBuf = !!(tmp.f & ISPOLN );
    ::ksSpcVisible( SPC_NAME, 2, uBuf );
    if ( uBuf )
    {
      uBuf = 2;
      ::ksSpcChangeValue( SPC_NAME, 2, &uBuf, UINT_ATTR_TYPE  );
    }

    // Изменим диаметр
    ::ksSpcChangeValue( SPC_NAME, 4, &tmp.d, FLOAT_ATTR_TYPE  );

    // Отследим мелкий шаг
    uBuf = !(tmp.f & PITCHOFF || !(tmp.f &PITCH));
    ::ksSpcVisible( SPC_NAME, 5, uBuf );
    ::ksSpcVisible( SPC_NAME, 6, uBuf ); // Шаг
    if ( uBuf )
      ::ksSpcChangeValue( SPC_NAME, 6, &tmp.p2, FLOAT_ATTR_TYPE );

    // Изменим длину
    uBuf = (UINT)tmp.l;
    ::ksSpcChangeValue( SPC_NAME, 9, &uBuf, UINT_ATTR_TYPE  );

    if( !flagMode )
    {
      ::ksSpcVisible( SPC_NAME, 7,  0 ); // Выключим поле допуска
      ::ksSpcVisible( SPC_NAME, 10, 0 ); // Выключим класс прочности
      ::ksSpcVisible( SPC_NAME, 11, 0 ); // Выключим материал
      ::ksSpcVisible( SPC_NAME, 12, 0 ); // Выключим покрытие
    }

    // Изменим ГОСТ
    uBuf = tmp.gost;
    ::ksSpcChangeValue( SPC_NAME , 14, &uBuf, UINT_ATTR_TYPE  );
    float  massa  = tmp.f & ISPOLN ? tmp.m2 : tmp.m1;
    massa = massa*( !tmp.indexMassa ? 1 : tmp.indexMassa==1 ? 0.356f : tmp.indexMassa==3 ? 0.97f : 1.08f )/COUNT_MASSA;

    char buf[128];
    sprintf( buf, "%f" , massa );
    ksSpcMassa ( buf ); // Масса детали

    // Подключим геометрию
    specification->SpcIncludePart( part, false );

    return ::ksSpcObjectEnd();
  }
  return 0;
}


//-------------------------------------------------------------------------------
// Отрисовка объекта спецификации
// ---
bool Shpeel::DrawSpcObj() 
{
  spcObj = 0;
  if( obj->IsSpcObjCreate() ) 
  {
    if ( ReturnResult() == etError10 ) // Вырожденный объект
      ResultNULL();

    spcObj = obj->EditSpcObj( spcObj );
    if( !obj->par.flagAttr && spcObj ) 
    {
      ::DeleteObj( spcObj );
      spcObj = 0;
    }
  }
  return !!spcObj;
}



//-------------------------------------------------------------------------------------
// Рисование 3D объектов
// ---
void Shpeel::Draw3D( Kompas6api3d5com_tlb::IDocument3DPtr & _doc )
{
  if ( _doc )
  {
    doc = _doc;
    flagMode = doc->IsEditMode() ;
    obj = this;

    // Взяли деталь
    part.Bind( doc->GetPart( flagMode ? pEdit_Part : pNew_Part ), false/*AddRef*/ );
    if ( part )
    {
      // После определения детали нужно считать параметры редактирования
      if ( flagMode )
        GetParam();

      if ( obj->MacroElementParam()== IDOK )
      {
        Kompas6api3d5com_tlb::IRequestInfoPtr info( doc->GetRequestInfo(part), false/*AddRef*/ );
        if ( info )
        {
          // Укажите точку привязки детали
          WideString wstr( _LoadStr( flagMode ? STR_SELECT_PLANE : STR_SELECT_POINT ) );
          info->SetPrompt( wstr.c_bstr() );
          SetCallBackAndFilterFunction( info );
          if ( doc->UserGetPlacementAndEntity(3) )
          {
            part->SetPlacement( Kompas6api3d5com_tlb::IPlacementPtr(info->GetPlacement(), false/*AddRef*/ ) );
            wstr = obj->SetFileName();
            // Устанавливаем признак, стандартное изделие
            part->SetStandardComponent( true );
            SetParam();

            if ( IsCollectionEmpty(info) )   // Указали placement
              part->UpdatePlacement();       // Изменм положение детали
            if ( flagMode || doc->SetPartFromFile( wstr.c_bstr(), part, false ) )
            {
              if ( IsCollectionChange(info) )  // Массив Mate'ов изменился
              {
                if ( flagMode )                // Режим редактирования
                  SetMates( doc, info, true ); // Удалить сопряжения
                SetMates( doc, info );         // Cоздать сопряжения
              }
            }
            DrawSpcObj(); // Создать объект СП

            if ( spcObj ) // Вывод объекта СП
            {
              // Редактируем параметры
              ::ksEditWindowSpcObject( spcObj );
              spcObj = 0;
            }
          }
        }
      }
    }
  }
}


//------------------------------------------------------------------------------
// Функция фильтр
// ---
bool WINAPI SELECTFILTERPROC( Kompas6api3d5com_tlb::IEntityPtr & entity )
{
  bool res = false; // Выделять нельзя если объект есть
  if ( entity )
  {
    Kompas6api3d5com_tlb::IPartPtr entPart( entity->GetParent(), false/*AddRef*/ ); // Деталь присланного объекта если деталь другая
    if ( (Kompas6api3d5com_tlb::IPart*)entPart != (Kompas6api3d5com_tlb::IPart*)obj->GetPart() )
      // Проверяем объект на принадлежность к плоскости, конической поверхности или оси
      res = IsSurface( entity ) ||
            IsSurface( entity, false /*planar*/ ) ||
            IsAxis( entity );   
  }                                               
  return res;
}


//------------------------------------------------------------------------------
// Функция обратной связи
// Состав collection ( 0 - плоскость, 1 - цилиндр, 2 - ось ) 
// ---
int WINAPI SELECTCALLBACKPROC( Kompas6api3d5com_tlb::IEntity * _entity, Kompas6api3d5com_tlb::IRequestInfo * _info )
{
  Kompas6api3d5com_tlb::IRequestInfoPtr info;
  info.Bind( _info, true/*AddRef*/ );

  if ( info ) {
    Kompas6api3d5com_tlb::IEntityPtr entity;
    entity.Bind( _entity, true/*AddRef*/ );

    Kompas6api3d5com_tlb::IEntityCollectionPtr collection( info->GetEntityCollection(), false/*AddRef*/ );

    if ( collection )
    {
      if ( entity )
      {
        int res = 0;
        if ( IsSurface(entity) )
        {
          // При повторном указании объекта снимаем с него выбор
          Kompas6api3d5com_tlb::IEntityPtr oldPlane( collection->GetByIndex(0), false/*AddRef*/ );
          if ( (Kompas6api3d5com_tlb::IEntity*)oldPlane == _entity )
            collection->SetByIndex( NULL,   0 ); // Обнулить плоскость
          else
            collection->SetByIndex( entity, 0 ); // Заменить плоскость

          res = 1;
        }

        if ( IsSurface(entity, false /*planar*/) )
        {
          // При повторном указании объекта снимаем с него выбор
          Kompas6api3d5com_tlb::IEntityPtr oldPlane( collection->GetByIndex(1), false/*AddRef*/ );
          if ( (Kompas6api3d5com_tlb::IEntity*)oldPlane == _entity )
            collection->SetByIndex( NULL,   1 ); // Обнулить коническую плоскость
          else
          {
            collection->SetByIndex( entity, 1 ); // Заменить коническую плоскость
            collection->SetByIndex( NULL,   2 ); // Обнулить ось
          }
          res = 1;
        }

        if ( IsAxis(entity) )
        {
          // При повторном указании объекта снимаем с него выбор
          Kompas6api3d5com_tlb::IEntityPtr oldAxis( collection->GetByIndex(2), false/*AddRef*/ );
          if ( (Kompas6api3d5com_tlb::IEntity*)oldAxis == _entity )
            collection->SetByIndex( NULL,   2 ); // Обнулить ось
          else
          {
            collection->SetByIndex( entity, 2 ); // Заменить ось
            collection->SetByIndex( NULL,   1 ); // Обнулить коническую плоскость
          }
          res = 1;
        }


        if ( res )
          obj->GetCollectChanged() = true;
        // Укажите точку привязки детали
        WideString wstr( _LoadStr( STR_SELECT_PLANE ) );
        info->SetPrompt( wstr.c_bstr() );

        return res;
      }
      else
      {
        for ( int i = 0; i < 3; i++ )
          collection->SetByIndex( NULL, i ); // Обнулить
        // Укажите точку привязки детали
        WideString wstr( _LoadStr( STR_SELECT_PLANE ) );
        info->SetPrompt( wstr.c_bstr() );
        return 1;
      }
    }
  }
  return 0;
}


//------------------------------------------------------------------------------
// Заполняет адреса функций фильтра и обратной связи
// ---
void Shpeel::SetCallBackAndFilterFunction( Kompas6api3d5com_tlb::IRequestInfoPtr & info )
{
  info->SetFilterCallBack( SELECTFILTERPROC );
  info->SetCallBack( SELECTCALLBACKPROC );
}


//------------------------------------------------------------------------------
// Проверяет содержимое массива - возвращает true если нужно перестроить Mate'ы
// ---
bool Shpeel::IsCollectionChange( Kompas6api3d5com_tlb::IRequestInfoPtr & info )
{
  bool res = true;
  if ( !collectChanged ) // Если новые объекты не указывали - сравниваем массивы
  {
    // Возможен вариант когда указали точку и массив в info заполнен NULL'ми а старый нет
    res = false; // Не надо перестраивать
    Kompas6api3d5com_tlb::IEntityCollectionPtr collection1( info->GetEntityCollection(), false/*AddRef*/ );        // Новый массив
    Kompas6api3d5com_tlb::IEntityCollectionPtr collection2( part->GetMateConstraintObjects(), false/*AddRef*/  );  // Старый массив
    if ( (bool)collection1 && (bool)collection2 &&
         ( collection1->GetCount() > 2 ) &&
         ( collection2->GetCount() > 2 ) )
    {
      for( int i = 0; i < 3; i++ ) // Цикл по массивам
      {
        Kompas6api3d5com_tlb::IEntityPtr ent1( collection1->GetByIndex(i), false/*AddRef*/ ); // Текущий элемент 1
        Kompas6api3d5com_tlb::IEntityPtr ent2( collection2->GetByIndex(i), false/*AddRef*/ ); // Текущий элемент 2
        if ( (Kompas6api3d5com_tlb::IEntity*)ent1 != (Kompas6api3d5com_tlb::IEntity*)ent2 ) // Если они не равны
        {                 
          res = true; // Перестраиваем
          break;
        }
      }
    }
  }
  return res; 
}



//------------------------------------------------------------------------------
// Устанавливает сопряжения
// ---
void Shpeel::SetMates( Kompas6api3d5com_tlb::IDocument3DPtr & doc, Kompas6api3d5com_tlb::IRequestInfoPtr & info, bool delMates )
{
  Kompas6api3d5com_tlb::IEntityCollectionPtr collection( !delMates ? info->GetEntityCollection() : part->GetMateConstraintObjects(), false/*AddRef*/ );
  if ( collection )
  {
    if ( (bool)doc && collection->GetCount() > 2 )
		{
			if ( !delMates )
				::AddMates( *this, doc, collection );
			else
				::DelMates( *this, doc, collection );
    }
    if ( !delMates )
      part->SetMateConstraintObjects( collection );
  }
}

   
//------------------------------------------------------------------------------
// Находит у детали поверхность с заданным именем
// ---
Kompas6api3d5com_tlb::IEntityPtr Shpeel::GetEntityByName( wchar_t * name )
{
  Kompas6api3d5com_tlb::IEntityPtr entity;
  if ( part )
  {
    if ( !collect )  // Массив лежит в классе, и если он ещё не создан - создаём
      collect.Bind( part->EntityCollection(o3d_constrElement), false/*AddRef*/ );

    entity.Bind( collect->GetByName( name, true, true ), false/*AddRef*/ );
  }
  return entity;
}


//------------------------------------------------------------------------------
// массив пуст - указали placement
// ---
bool Shpeel::IsCollectionEmpty( Kompas6api3d5com_tlb::IRequestInfoPtr & info )
{
  bool res = true; // Массив пуст
  Kompas6api3d5com_tlb::IEntityCollectionPtr collection( info->GetEntityCollection(), false/*AddRef*/ ); // Новый массив
  if ( collection )
    for( int i = 0, count = collection->GetCount(); i < count; i++ ) // Цикл по массиву
    {
      Kompas6api3d5com_tlb::IEntityPtr entity( collection->GetByIndex(i) ); // Текущий элемент
      if ( entity )                                       // Если он не NULL
      {
        res = false;                                      // Массив не пуст
        break;                                            // Завершить цикл
      }
    }
  return res; // Результат
}


