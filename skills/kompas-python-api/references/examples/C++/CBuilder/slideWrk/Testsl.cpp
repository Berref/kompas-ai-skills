////////////////////////////////////////////////////////////////////////////////
//
// testsl.cpp - Тест слайд
//
// 1. Сдвинуть слайд   - MoveSlide         - <testmov.cpp> 
// 2. Записать слайд   - WriteSlideStep 
// 3. Отрисовать слайд - TestShowDialog 
// 4. Разбить слайд    - DecomposeSlideStep
//
////////////////////////////////////////////////////////////////////////////////
#ifndef __WINDOWS_
#include <windows.h>
#endif

#ifndef  __MATH_H
#include <math.h>
#endif

#ifndef __LIBTOOL_H
#include <libtool.h>
#endif


#ifndef __TESTSL_RH
#include "testsl.rh"
#endif

#ifndef __TESTMOVE_H
#include "testmov.h"
#endif

HINSTANCE _hinst;

//------------------------------------------------------------------------------
// в Win32 линкуется SDK/lib/kAPI2D5bc.lib
// в x64 линкуется SDK/lib64/kAPI2D5bc.a
// ---
#pragma comment(lib, "kAPI2D5bc")

//-------------------------------------------------------------------------------
// Описания используемых функций
// ---  
void WriteSlideStep();
void DecomposeSlideStep();
void TestShowDialog();
void symmetry( float x, float y,float x1, float y1,float x2, float y2,
               float *xc, float *yc );


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
extern "C" void far __export __stdcall LIBRARYENTRY( UINT comm )
{
  switch ( comm )
  {
    // Отрисовать слайд
    case 4 :
      TestShowDialog();
      break;
    
    default:  
    {
      if ( ksGetCurrentDocument( 1 ) ) // Получить активный 2D документ
      {
        switch ( comm )
        {
          // Сдвинуть слайд
          case 1 :
            MoveSlide();
            break;

          // Записать слайд
          case 2 :
            WriteSlideStep();  
            break;

          // Разбить слайд
          case 3 :
            DecomposeSlideStep();    
            break;
        }
      }
      else
        Message( "Документ не активизирован или\nне является листом/фрагментом" );        
    }
  }
}


//-------------------------------------------------------------------------------
// Записать слайд
// ---
void WriteSlideStep()
{
  char name[255];
  // Выберем файл для записи
  if ( SaveFile( "*.rc", NULL, NULL, name, 255 ) )
  {
    // Структура параметров запроса к системе
    RequestInfo info;
    memset( &info, 0, sizeof( info ) );
    
    // Строка или идентификатор меню состава команд 
    info.commands = "Укажите точку привязки слайда";

    double x, y; // Точка привязки слайда - верхний левый угол габаритного прямоугольника слайда
    
    // Интерактивный ввод точки или комманды
    if ( Cursor( &info,   // Указатель на структуру параметров запроса к системе	
                 &x,      // Координаты введенной точки	
                 &y, 
                 NULL ) ) // Указатель на структуру управления фантомом, определяющую тип	движения курсора
    {
      int slideId;
      // Ввод целого числа
      if ( ReadInt( "Введите идентификатор слайда", 100, 0, 32000, &slideId ) )
      {
        // Записать слайд
        if ( !WriteSlide( name,    // Имя файла для записи 
                          slideId, // Идентификатор слайда в файле ресурсов
                          x, y ) ) // Базовая точка
          Error( "Группа селектирования пуста" );
        ClearGroup( 0 ); // Очистить группу объектов, если 0, то очистится группа селектирования 
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Глобальные переменные
// ---
static double g_x1, g_y1, g_x2, g_y2;
static int g_flag;


//-------------------------------------------------------------------------------
// Отросовка рамки
// ---
static void DrawRamka() 
{
  if( fabs( g_y1 - g_y2 ) >0 ) 
  {
    LineSeg( g_x1, g_y1, g_x1, g_y2, 1 );
    LineSeg( g_x2, g_y1, g_x2, g_y2, 1 );
  }
  if( fabs( g_x1 - g_x2 ) >0 ) 
  {
    LineSeg( g_x1, g_y1, g_x2, g_y1, 1 );
    LineSeg( g_x1, g_y2, g_x2, g_y2, 1 );
  }
}


//-------------------------------------------------------------------------------
// Функция обратной связи, вызываемая из Cursor
// ---
int WINAPI CallBackC( int comm,             // Пришедшая команда
                      double *x, double *y, // Положение фантома
                      RequestInfo *info,    // Структура параметров запроса к системе
                      void *phantom,        // Структура параметров фантома
                      int dynamic )
{
  Phantom *pPhantom = ( Phantom * )phantom;

  if( !dynamic ) // Фиксация
  { 
    if( !g_flag ) // Фиксируется 1 точка
    {
      g_flag++;
      g_x1 = *x; 
      g_y1= *y;
      info->commands = "Укажите вторую точку окна";
    }
    else 
    {
      g_flag++;
      g_x2 = *x; 
      g_y2 = *y;
      return 0;
    }
  }
  else  
  {
    if( g_flag > 0 )
    {
      g_x2 = *x; 
      g_y2 = *y;
      pPhantom->type1.xBase = g_x2; 
      pPhantom->type1.yBase = g_y2;
      if ( pPhantom->type1.gr)
        DeleteObj( pPhantom->type1.gr );
      
      pPhantom->type1.gr = NewGroup( 1 ); // Временная группа
        DrawRamka();
      EndGroup();
    }
  }
  return 1;
}


//-------------------------------------------------------------------------------
// Разбить слайд
// ---
void DecomposeSlideStep() 
{
  double x, y;
  RequestInfo  info;
  memset( &info, 0, sizeof(info));
  info.commands   = "Укажите первую точку окна";
  info.dynamic    = 1;
  info.callBack   = CallBackC; // Указываем адрес обратной функции для Cursor
  Phantom par;
  par.phType      = 1;
  par.type1.gr    = NewGroup( 1 );
  EndGroup();
  par.type1.xBase = 0; 
  par.type1.yBase = 0;
  par.type1.scale = 1;
  par.type1.ang   = 0;
  g_flag          = 0;

  Cursor(&info,&x,&y,&par);
  if ( par.type1.gr)
    DeleteObj( par.type1.gr );
  if( g_flag == 2 )
  {
    ClearGroup(0);
    if(SelectGroup( 0, 1, g_x1, g_y1, g_x2, g_y2 ) ) 
    {
      reference iGrp = CreateIterator ( SELECT_GROUP_OBJ, 0 );
      if ( iGrp )
      {
        par.type1.gr = NewGroup( 1 );
        EndGroup();
        reference rObj;
        reference gr;
        if ( ExistObj( rObj = MoveIterator ( iGrp, 'F' )) ) 
        {
          do 
          {
            gr = DecomposeObj( rObj, 0, 0.2, 0 );
            AddObjGroup( par.type1.gr, gr );
            ksClearGroup( gr, false );
            DeleteObj( gr );
          } while( ExistObj ( rObj = MoveIterator( iGrp, 'N' )) );
        }

        memset( &info, 0, sizeof(info));
        par.type1.xBase = g_x1; 
        par.type1.yBase = g_y1;
        info.commands = "Укажите базовую точку группы";
        if( Cursor( &info, &x, &y, &par ) ) 
        {
          Mtr( x - g_x1, y - g_y1, 0, 1 );
            TransformObj( par.type1.gr );
          DeleteMtr();
          StoreTmpGroup( par.type1.gr );
        }
        ClearGroup( par.type1.gr );
        DeleteObj( par.type1.gr );
      }
      ClearGroup(0);
    }
    else
      Error("Ошибка");
  }
} 