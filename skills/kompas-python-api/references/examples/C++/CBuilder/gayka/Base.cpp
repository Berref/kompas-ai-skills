////////////////////////////////////////////////////////////////////////////////
//
// base.cpp - Базовые классы, структуры, функции 
//
////////////////////////////////////////////////////////////////////////////////
#ifndef __DHEAD_H
#include  "dhead.h"
#endif

#pragma hdrstop

#include <objbase.h>
#include <initguid.h>

#ifndef __LIBHPPAR_H
#include "libhppar.h"
#endif

#ifndef __BASDE_H
#include "base.h"
#endif

#include <ksConstants.h>

#if !defined(_IFUNC)
# define _IFUNC STDMETHODCALLTYPE
#endif

//------------------------------------------------------------------------------
// в Win32 линкуется SDK/lib/kAPI2D5bc.lib
// в x64 линкуется SDK/lib64/kAPI2D5bc.a
// ---
#pragma comment(lib, "kAPI2D5bc")

//-------------------------------------------------------------------------------
// 
// ---
CPar * obj;
bool flagSwitch;           // false - переключения нет, true - переключение с Placement на Cursor
static bool flagCalcPaket; // true - нужно считать длину пакета

char buf[_MAX_PATH];
reference CPar::spcObj[MAX_COUNT_SPCOBJ];

char ConstrHelp::helpName[250];
bool ConstrHelp::helpErr     = ConstrHelp::GetHelpFileName();
uint ConstrHelp::command     = 0;
bool ConstrHelp::commandHelp = false;

HINSTANCE _hinst;


//------------------------------------------------------------------------------
// Загрузить строку из ресурса
// ---
char* LoadStr( int id, char* str, int size )
{
  AnsiString tmp;
  tmp.LoadStr( id );
  ::strcpy( str, tmp.c_str() );
  char buf[255];
  if ( ::ksConvertLangStr(str, buf, size) )
    ::strcpy( str, buf );
  return str;
}


//-------------------------------------------------------------------------------
// Имя файла помощи
// --- 
int ConstrHelp::GetHelpFileName()
{
  if( ::GetModuleFileName( _hinst, ConstrHelp::helpName, _MAX_PATH) )
  {
    char *c = strrchr( ConstrHelp::helpName, '\\');
    if ( c )
    {
      *(c+1) = '\0';
      strcat ( ConstrHelp::helpName, LIB_HELPFILE  );
      OFSTRUCT ofs;
      if ( OpenFile(ConstrHelp::helpName , &ofs, OF_EXIST) != HFILE_ERROR )
        return 1;
    }
  }
  return 0;
}


//-------------------------------------------------------------------------------
// Задать идентификатор ресурсов
// --- 
extern "C" unsigned int far __export __stdcall LIBRARYID()
{
	return MENU_1;
}


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// --- 
extern "C" void far __export __stdcall LIBRARYENTRY( UINT Comm )
{
  CPar * par = NULL;
  ConstrHelp::SetCommand( Comm );

	switch ( Comm ) 
	{
  	case 1 : par = new Gayka5915(5915); break;
  } 

  if( par ) 
  {
    par->Draw1();
    delete par;
  }
}


// HOT_POINTS ##################################################################

//-------------------------------------------------------------------------------
// Накрутка для работы с Hot-точками
// ---
class Gayka5915HP : public /*TUnknown, protected*/ ILibHPObject 
{
  protected :
    Gayka5915 obj;
    int count;
  public :
    Gayka5915HP() : obj(5915), count (0) {};
   ~Gayka5915HP();
  public:
    virtual unsigned long   _IFUNC AddRef();
    virtual unsigned long   _IFUNC Release();
    virtual HRESULT         _IFUNC QueryInterface(const GUID far& iid, void far*far* iface);
    virtual int             _IFUNC LibHotPnt_GetMenu       ()                                        { return obj.GetMenu(); }
    virtual BOOL            _IFUNC LibHotPnt_Prepare       ( int index )                             { return TRUE; }
    virtual BOOL            _IFUNC LibHotPnt_Complete      ( int index, BOOL success )               { return obj.EditComplete( index, success ); }
    virtual BOOL            _IFUNC LibHotPnt_Get           ( HotPointDescription* point, int index ) { return obj.GetHotPoints( point, index ); }
    virtual BOOL            _IFUNC LibHotPnt_Set           ( HotPointDescription* point, int index ) { return obj.SetHotPoint( point, index ); }
    virtual BOOL            _IFUNC LibHotPnt_GetCursorText ( int index, char** text )                { return obj.GetCursorText( index, text ); }
    virtual BOOL            _IFUNC LibHotPnt_ExecuteCommand( int id )                                { return obj.ExecuteCommand( id ); }
};


//-------------------------------------------------------------------------------
// TUnknown
// --- 
unsigned long _IFUNC Gayka5915HP::AddRef()
{
  count++;
  return count;
}


//-------------------------------------------------------------------------------
// TUnknown
// --- 
unsigned long _IFUNC Gayka5915HP::Release() 
{
  count--;
  unsigned long rez = count;
  if( !count )
    delete this;
  return rez;
}


//------------------------------------------------------------------------------
// TUnknown
// ---
HRESULT _IFUNC Gayka5915HP::QueryInterface(const GUID far& iid, void far*far* iface)
{
  if ( iid == IID_ILibHPObject )
  {
    *iface = this;
    return S_OK;
  }
  *iface = NULL;
  return E_NOINTERFACE;
}


//-------------------------------------------------------------------------------
// Получить интерфейс работы с Hot-точками
// ---
extern "C" void far __export __stdcall LibObjInterfaceEntry( int idType, unsigned int Comm, ILibHPObject** object ) 
{
  if ( object ) 
  {
    if ( idType == 1 ) // Если не hot точки обнулить
      switch (Comm) 
      {
        case 1 : *object = new Gayka5915HP(); (*object)->AddRef(); break;
      }
  }
}


//-------------------------------------------------------------------------------
// 
// --- 
Gayka5915HP::~Gayka5915HP() 
{
} 

// HOT_POINTS ##################################################################


//-------------------------------------------------------------------------------
// 
// --- 
CPar::CPar() 
{
  par.flagAttr    = 0;
  par.typeSwitch  = 0;
  par.angle       = 0;
  par.drawType    = 0;
  refMacr = (reference*) new char[sizeof(reference)];
  countObj = 1;
}

//-------------------------------------------------------------------------------
// Вывод ошибки если она возникла
// --- 
void CPar::_MessageBoxResult() 
{
  if ( ReturnResult() )
  {
    if ( ReturnResult() == etError10 ) // Вырожденный объект
      ResultNULL();
    else
      MessageBoxResult();
  }
}


//-------------------------------------------------------------------------------
// 
// --- 
CPar::~CPar()
{
  delete [] refMacr;
}


//-------------------------------------------------------------------------------
// Оператор присваивания
// --- 
void CPar::Assign( const CPar &other ) 
{
  // Годится для всех элементов кроме "Болт шайба гайка"
	memcpy( refMacr, other.refMacr, sizeof((*refMacr)) );
  flagMode    = other.flagMode;
  par         = other.par;
}


//-------------------------------------------------------------------------------
// Отрисовка объекта спецификации  
// --- 
bool CPar::DrawSpcObj( reference geom )
{
  memset( spcObj, 0, sizeof(reference)*MAX_COUNT_SPCOBJ );
  if( obj->IsSpcObjCreate() )
  {
    if ( ReturnResult() == etError10 )    // Вырожденный объект
      ResultNULL();

    spcObj[0] = obj->EditSpcObj( spcObj, geom );
    if( !obj->par.flagAttr && spcObj )
    {
      for ( uint i = 0, count = obj->GetObjCount(); i < count; i++ ) 
      {
        if( spcObj[i] ) 
        {
          if ( ::ksSpcObjectEdit( spcObj[i] ) ) 
          {
            ::ksSpcIncludeReference( 0, 0 ); // Очистим геометрию, чтобы не удалялась в месте с объектом  
            ::ksSpcObjectEnd();
          }  
          ::DeleteObj ( spcObj[i] );
          spcObj[i] = 0;
        }
      }
    }  
  }
  return ( bool ) spcObj[0];
}


//-------------------------------------------------------------------------------
// Изменение положения макро объекта 
// --- 
void CPar::SetPlacement( double x, double y, double angl ) 
{
  if ( refMacr )
    ::SetMacroPlacement( *refMacr, x,  y,  angl, 0 );
}


//-------------------------------------------------------------------------------
// Функция обратной связи, вызываемая из Placement
// --- 
int far __export __stdcall CPar::CallBackP ( int com, double *x,
                                          double *y, double *angl,
                                          RequestInfo *info,
                                          void *phantom,
                                          int dynamic ) 
{
  Phantom *rub = (Phantom *)phantom;
  if( !dynamic ) // Фиксация
  { 
    switch ( com ) 
    {
      case ID_ANGLE  :
        flagSwitch = true;
        return 0;
      case ID_CALC_PAKET :
        flagCalcPaket = true;
        return 0;
      case ID_VID       :
      case ID_TOPVID    :
      case ID_SIDEVID   :
      case ID_VIDSEC    :
      case ID_SEC       :
      case ID_VID_R     :
      case ID_SEC_R     :
      case ID_BOTTOMVID :
      case ID_SHPONSLOT :
        obj->par.drawType =(short) com;
        obj->FuncAfteDrawType();
        break;
      case ID_HATCH_ANG :
        obj->SetHatchAngl();
        break;
      case ID_HATCH_SHAG :
        obj->SetHatchShag();
        break;
      case ID_SIMPLE :
        obj->SetSimple();
        break;
      case ID_DIMENSION :
        obj->SetDimension();
        break;
      case ID_SERVICE  :
        obj->ServiceObj();
        break;
      case ID_ATTR :
        obj->SetAttr();
        break;
      case ID_PARAM :
        obj->MacroElementParam();
        break;
      case -1: // Поставить в модель
        obj->par.angle = *angl;
        obj->SetParam();
        
// HOT_POINTS ##################################################################
        obj->ServiceObj1( *x, *y );
        obj->SetPlacement( *x, *y, *angl );
        ::StoreTmpGroup( rub->type1.gr );
// HOT_POINTS ##################################################################
        
        if ( DrawSpcObj( rub->type1.gr ) ) 
        {
          ClearGroup( rub->type1.gr );
          return 0;
        }
        ClearGroup( rub->type1.gr );
        if( obj->flagMode )
          return 0;
        break;
    }
    info->commands = (char *)obj->ChoiceMenuId();
    obj->GetGroup ( rub->type1.gr );
  }
  else
  {
    obj->par.angle = *angl;
  }
  return 1;
}


//-------------------------------------------------------------------------------
// Функция обратной связи, вызываемая из Cursor
// --- 
int far __export __stdcall CPar::CallBackC ( int com, double *x,
                                          double *y,
                                          RequestInfo *info,
                                          void *phantom,
                                          int dynamic ) 
{
  Phantom *rub = (Phantom *)phantom;

  if( !dynamic ) // Фиксация
  { 
    switch ( com ) 
    {
      case ID_ANGLE  :
        flagSwitch = true;
        return 0;
      case ID_CALC_PAKET :
        flagCalcPaket = true;
        return 0;
      case ID_VID     :
      case ID_TOPVID  :
      case ID_SIDEVID :
      case ID_VIDSEC  :
      case ID_SEC     :
      case ID_VID_R   :
      case ID_SEC_R   :
      case ID_BOTTOMVID :
      case ID_SHPONSLOT :
        obj->par.drawType =(short) com;
        obj->FuncAfteDrawType();
        break;
      case ID_HATCH_ANG :
        obj->SetHatchAngl();
        break;
      case ID_HATCH_SHAG :
        obj->SetHatchShag();
        break;
      case ID_SIMPLE :
        obj->SetSimple();
        break;
      case ID_DIMENSION :
        obj->SetDimension();
        break;
      case ID_SERVICE  :
        if( !obj->ServiceObj() ) 
        {
          flagSwitch = true;
          return 0;
        }
        break;
      case ID_ATTR :
        obj->SetAttr();
        break;
      case ID_PARAM :
        obj->MacroElementParam();
        break;
      case -1: // Поставить в модель
        obj->SetParam();
        
// HOT_POINTS ##################################################################
        obj->ServiceObj1( *x, *y );
        obj->SetPlacement( *x, *y, obj->par.angle );
        ::StoreTmpGroup( rub->type1.gr );
// HOT_POINTS ##################################################################

        if ( DrawSpcObj( rub->type1.gr ) )
        {
          ClearGroup( rub->type1.gr );
          return 0;
        }
        ClearGroup( rub->type1.gr );
        if( obj->flagMode )
          return 0;
        break;
    }
    info->commands = (char *)obj->ChoiceMenuId();
    obj->GetGroup ( rub->type1.gr );
  }
  return 1;
}


//-------------------------------------------------------------------------------
// Отрисовать позиционную линию выноски
// уже проверено , что объект спецификации есть
// Функцию нужно запускать вне Cursor и Placement
// ---
void CPar::DrawPosLeader( reference _spcObj ) 
{
  RequestInfo info;
  bool flag = false;
  reference posLeater = 0;
  double x1, y1;
  char buf[128];
  
  do
  {
    memset(&info, 0, sizeof(info) );
    info.commands = (char*)MENU_POS_LEADER;
    info.prompt = LoadStr( STR226, buf, sizeof(buf) ); // Укажите позиционную линию выноски
    int j1 = Cursor( &info, &x1, &y1, 0 );
    switch ( j1 )
    {
      case 1: // Создать новую линию выноски
        posLeater = ::ksCreateViewObject( POSLEADER_OBJ );
        flag = false;
        break;
      case 2: // Подключить существующую
        memset(&info, 0, sizeof(info) );
        info.commands = LoadStr( STR226, buf,sizeof(buf) ); // Укажите линию выноски.
        if( Cursor( &info, &x1, &y1, 0 ) )
        {
          posLeater = ::FindObj( x1, y1, 100 ); // Величина стороны окошка-ловушки с центром x,y
          if ( !(posLeater && ::GetObjParam( posLeater, 0, 0, 0) == POSLEADER_OBJ ))
          {
             Error( LoadStr(STR228, buf, sizeof(buf)) ); // Объект не позиционная линия выноски!
             posLeater = 0;
             flag = true;
          }
          else
            flag = false;
          break;
        }
        else
          flag = false;
        break;
      case -1:
        posLeater = ::FindObj( x1, y1, 100 ); // Величина стороны окошка-ловушки с центром x,y
        if ( !(posLeater && ::GetObjParam( posLeater, 0, 0, 0) == POSLEADER_OBJ ))
        {
           ::Error( LoadStr(STR228, buf,sizeof(buf)) ); // Объект не позиционная линия выноски!
           posLeater = 0;
           flag = true;
        }
        else
          flag = false;
      break;
      case 0 :
        flag = false;
      break;
    }
  }  
  while( flag );
  
  // Линия выноски есть, подключим ее к объекту спецификации 
  if ( posLeater  ) 
  {
    // Ввойдем в режим редактирования объекта спецификации
    if ( ::ksSpcObjectEdit( _spcObj ) ) 
    {
      // Подключим линию выноски
      ::ksSpcIncludeReference( posLeater, true );
      // Закроем объект спецификации
      ::ksSpcObjectEnd();
    }
  }
}


//-------------------------------------------------------------------------------
// Отрисовка геометрии 1
// --- 
void CPar::Draw1() 
{
  struct Phantom  rub;
  rub.type1.xBase = 0;
  rub.type1.yBase = 0;
  int j           = 1;
  rub.type1.scale = 1;
  rub.phType      = 1;
  rub.type1.gr    = 0;
  double x, y;
  if ( !ReturnResult() ) 
  {
    flagMode = EditMacroMode( );
    obj = this;
    if ( obj->MacroElementParam()!= IDOK )
      return;
    while ( j )
    {
      flagSwitch = 0;
      flagCalcPaket = false;
      GetGroup ( rub.type1.gr );
      rub.type1.ang  = par.angle;

      int menuId = ChoiceMenuId ( );

      RequestInfo info;
      memset(&info, 0, sizeof(info) );
      info.commands = (char *)menuId;
      info.dynamic = 1;
      info.title = (char*)PROMPT;
      info.prompt = (char*)PROMPT;
      if ( par.typeSwitch ) 
      {
        info.callBack = &CallBackC;
        j=Cursor( &info, &x, &y, &rub );
      }
      else
      {
        info.callBack = &CallBackP;
        j=Placement( &info, &x, &y,
                     &rub.type1.ang,
                     &rub );
      }

      if ( spcObj[0] )
      {
        for( uint i = 0, count = obj->GetObjCount(); i < count; i++ ) 
        {
          if (::ksEditWindowSpcObject( spcObj[i] )) 
          {
            DrawPosLeader(spcObj[i]);
          }
        }
        memset( spcObj, 0, sizeof(reference)*MAX_COUNT_SPCOBJ );
        if ( !flagMode ) 
        {
          flagSwitch = true;
          par.typeSwitch ? par.typeSwitch = 0 : par.typeSwitch = 1;
        }
      }

      if ( flagSwitch ) 
      {
        j = 1;
        par.typeSwitch ? par.typeSwitch = 0 : par.typeSwitch = 1;
      }
      if ( flagCalcPaket )
      {
        obj->CalkPaket();
        j = 1;
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Редактирование и вставка объекта спецификации, если он был создан
// --- 
BOOL Gayka5915::EditComplete( int index, BOOL success ) 
{
  if ( index == 1 && success ) 
  {
  	obj = this;
  	DrawSpcObj( 0 );
    if ( spcObj[0] ) 
    {
      for( uint i = 0, count = obj->GetObjCount(); i < count; i++ ) 
      {
        if (::ksEditWindowSpcObject( spcObj[i] )) 
        {
          DrawPosLeader(spcObj[i]);
        }
      }
    }
  }
  return TRUE;
}


//-------------------------------------------------------------------------------
// Выполнение команды  
// --- 
BOOL Gayka5915::ExecuteCommand( int id ) 
{
  double x;
  double y;
  double alpha;
  if ( ::GetMacroPlacement( 0, &x, &y, &alpha ) ) 
  {
    switch ( id ) 
    {
      case ID_PARAM :
        if ( MacroElementParam() )
				  EditComplete( 1/*index*/, true/*success*/ );
        break;
      case ID_VID :
      case ID_TOPVID :
      case ID_SIDEVID :
      case ID_VIDSEC :
        par.drawType = (short)id;
        FuncAfteDrawType();
        break;
      case ID_HATCH_ANG :
        SetHatchAngl();
        break;
      case ID_HATCH_SHAG :
        SetHatchShag();
        break;
    }

    reference gr = 0;
    GetGroup( gr );

    SetParam();
    ::SetMacroPlacement( *refMacr, 0., 0., 0., 1 );
    ::StoreTmpGroup( gr );
    ClearGroup( gr );
  }
  return true;
}


//-------------------------------------------------------------------------------
// Отрисовка геометрии
// --- 
void CPar::Draw()  
{
  int j = 1;
  struct Phantom  rub;
  rub.type1.xBase = 0;
  rub.type1.yBase = 0;

  rub.type1.scale = 1;
  rub.phType        = 1;

  double x, y;
  flagMode = EditMacroMode( );
  while( j )
  {
    GetGroup ( rub.type1.gr  );
    rub.type1.ang  = par.angle;
    int menuId = ChoiceMenuId();

    RequestInfo info;
    memset(&info, 0, sizeof(info) );
    info.commands = (char *)menuId;

    if ( par.typeSwitch )
      j = Cursor( &info, &x, &y, &rub );
    else
      j = Placement( &info, &x, &y,
                     &rub.type1.ang,
                     &rub );
    switch ( j ) 
    {
      case ID_ANGLE :
        par.typeSwitch ? par.typeSwitch = 0 : par.typeSwitch = 1;
        break;
      case ID_VID :
      case ID_TOPVID :
      case ID_SIDEVID :
      case ID_VIDSEC :
      case ID_SEC :
      case ID_VID_R :
      case ID_SEC_R :
      case ID_BOTTOMVID :
      case ID_SHPONSLOT :
        par.drawType =(short) j;
        obj->FuncAfteDrawType();
        break;
      case ID_HATCH_ANG :
        SetHatchAngl();
        break;
      case ID_HATCH_SHAG:
        SetHatchShag();
        break;
      case ID_SIMPLE :
        SetSimple();
        break;
      case ID_DIMENSION :
        obj->SetDimension();
        break;
    case ID_SERVICE :
      obj->ServiceObj();
      break;
      case ID_ATTR :
        SetAttr();
        break;
      case ID_PARAM :
        MacroElementParam();
        break;
      case -1: // Поставить в модель
        par.angle = rub.type1.ang;
        SetParam();
        MoveObj( rub.type1.gr, x, y );
        if( fabs(rub.type1.ang) > 0.001 )
           RotateObj( rub.type1.gr, x, y, rub.type1.ang );
        obj->ServiceObj1( x, y );
        StoreTmpGroup( rub.type1.gr );
        DrawSpcObj( rub.type1.gr );
        ClearGroup( rub.type1.gr );
        if( flagMode )
          j = 0;
        break;
    }
  }
}


//-------------------------------------------------------------------------------
// Изменение угла штриховки
// --- 
float SetHatchAngl( float ang )
{
  double a;
  EnableTaskAccess( 0 );
  int rez =  ReadDouble( LoadStr(ANGLE_HATCH_STR, buf, sizeof(buf)), ang, -90, 90, &a );
  EnableTaskAccess( 1 );
  return rez ? a : ang;
}


//-------------------------------------------------------------------------------
// Изменение шага штриховки
// ---
float SetHatchShag( float shag)
{
  double a;
  EnableTaskAccess( 0 );
  int rez = ReadDouble( LoadStr(STEP_HATCH_STR, buf,sizeof(buf)), shag,0.1, 1000,&a );
  EnableTaskAccess( 1 );
  return ( rez ) ? a : shag;
}


//-------------------------------------------------------------------------------
// Отбросить дробную часть у строки если после "." нули
// "123.000" -> "123";   "123.10" -> "123.1"
// pointToComma =1 заменить '.' на ',' 
// --- 
void CheckDecimelPart(char *s,unsigned int pointToComma )
{
  if( s && strlen(s) ) 
  {
    char *c = strchr( s, '.');
    char *c1 = c;
    unsigned int flag = 0;
    if ( c1 ) 
    {
      c1++;
      while( *c1!='\0' && !flag ) 
      {
        if ( *c1 != '0' )
          flag = 1;
        c1++;
      }
      if( !flag )
        *c = '\0';
      else 
      {
        c1 = &s[ strlen(s)-1 ];
        while( *c1=='0' ) 
        {
          *c1 = '\0';
          c1--;
        }
        if ( pointToComma )
          *c = ',';
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Убрать пробелы у строки 
// --- 
int pr_str(char *vh, char *rez, int t)
{
  int i, j, k, m;

  j= strlen( vh );
  for ( i = j-1; i > 0; i-- )
    if ( *(vh+i) != ' ' )
      break;
  m = i;

  for ( i = 0; i < m; i++ )
    if ( *(vh+i) != ' ' )
      break;
  k = i;
  switch ( t ) 
  {
    case 'H' : i = k;        break;
    case 'E' : i = 0; j = m; break;
    case 'B' : i = k; j = m; break;
  }

  k = j - i;   
  for ( ;  i <= j; i++ )
    *rez++ = *( vh+i );
  *rez = '\0';

  return ( k );
}


//-------------------------------------------------------------------------------
// Ошибка в konstr.txt
// ---
void ErrorKonstr()
{
  Error( LoadStr(STR226, buf,sizeof(buf)) );
}


//-------------------------------------------------------------------------------
// Получить полное имя файла базы данных
// ---
int GetFullName( char *name, char *fName )
{
  if( ::GetModuleFileName( _hinst, fName, _MAX_PATH) )
  {
    char *c = strrchr( fName, '\\');
    if ( c ) 
    {
      *(c+1) = '\0';
      strcat ( fName, name );
      OFSTRUCT ofs;
      if ( OpenFile(fName , &ofs, OF_EXIST) != HFILE_ERROR )
        return 1;
      else 
      {
        *(c+1) = '\0';
        strcat ( fName, "LOAD\\" );
        strcat ( fName, name );
        if ( OpenFile(fName , &ofs, OF_EXIST) != HFILE_ERROR )
          return 1;
      }
    }
  }
  return 0;
}


//-------------------------------------------------------------------------------
// Открытие текстового файла 
// ---
reference _OpenTextFile( char *name )
{
  return GetFullName( name, buf  ) ? OpenTextFile( buf ) : OpenTextFile( name );
}


//-------------------------------------------------------------------------------
// Подключение к базе
// ---
int _ConnectDB(reference bd, char *name )
{
  return  GetFullName( name, buf  ) ? ConnectDB( bd, buf ) : ConnectDB( bd, name );
}


//-------------------------------------------------------------------------------
// Маштаб вида   
// ---
double GetViewScale()
{
  static ViewParam par;
  reference iView = CreateIterator( VIEW_OBJ , 0 );
  reference pView;
  if ( iView ) 
  {
    pView = MoveIterator ( iView, 'F'); // Первым будет системный вид с номером 0
    if ( pView ) 
    {
      do  
      {
        int state;
        GetObjParam( pView, &state, sizeof( int ), VIEW_LAYER_STATE );
        if ( state == stCURRENT ) 
        {
          GetObjParam( pView, &par, sizeof(par ), ALLPARAM );
          return par.scale;
        }
        pView = MoveIterator( iView, 'N');
      }
      while ( pView );
    }
    return 1;
  }
  else 
  {
    ResultNULL();
    return 1; // Фрагмент
  }
}


//-------------------------------------------------------------------------------
// Получение параметров у макро
// ---
int  _GetMacroParam( void * value, unsigned int size )
{
  return ::GetMacroParam( 0, value, size );
}


//-------------------------------------------------------------------------------
// Класс, позволяющий доступиться к caption и text у контрола
// ---
class TOpenControl : public TControl
{
public :
  __property Caption;
  __property Text;
};


//-------------------------------------------------------------------------------
// Функция перевода контрола
// ---
void ConvertLangControl( TOpenControl* opControl )
{
  if ( opControl )
  {
#if !defined( _UNICODE ) && !defined( _DELPHI_STRING_UNICODE )
    char buf[255];

    if ( ::ksConvertLangStr(opControl->Caption.c_str(), buf, MAX_TEXT_LENGTH) )
      opControl->Caption = buf;
    if ( ::ksConvertLangStr(opControl->Hint.c_str(), buf, MAX_TEXT_LENGTH) )
      opControl->Hint = buf;
    if ( ::ksConvertLangStr(opControl->Text.c_str(), buf, MAX_TEXT_LENGTH) )
      opControl->Text = buf;
#else
    wchar_t buf[255];

    if ( ::ksConvertLangStrW(opControl->Caption.c_str(), buf, MAX_TEXT_LENGTH) )
      opControl->Caption = buf;
    if ( ::ksConvertLangStrW(opControl->Hint.c_str(), buf, MAX_TEXT_LENGTH) )
      opControl->Hint = buf;
    if ( ::ksConvertLangStrW(opControl->Text.c_str(), buf, MAX_TEXT_LENGTH) )
      opControl->Text = buf;
#endif
  }
}


//-------------------------------------------------------------------------------------
// Функция перевода формы
//-------------------------------------------------------------------------------------
void ConvertLangForm( TForm* form )
{
  if ( form )
  {
    for ( int i = 0, count = form->ControlCount; i < count; i++ )
    {
      TControl* control = dynamic_cast<TControl*>( form->Components[i] );
      if ( control )
        ::ConvertLangControl( (TOpenControl*)control );
    }
    // Переводим радиогруппы и др оконные контролы
    ::ksConvertLangWindow( form->Handle );
  }
}

