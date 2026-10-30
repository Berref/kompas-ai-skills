//////////////////////////////////////////////////////////////////////////////// 
// 
// step3.cpp - Объекты
// 
// 1.  Создать документ - WorkDocument
// 2.  Виды             - DrawView
// 3.  Слои             - DrawLayer
// 4.  Группы           - DrawGroup
// 5.  Именная группа   - WorkNameGroup
// 6.  Отрезки          - DrawLineSeg
// 7.  Дуги             - DrawArc
// 8.  Линии            - DrawLine
// 9.  Окружности       - DrawCircle
// 10. Точки            - DrawPoint
// 11. Bezier-сплайны   - DrawBezier
// 12. Штриховка        - DrawHatch
// 13. Текст            - DrawText
// 
//////////////////////////////////////////////////////////////////////////////// 
#include <vcl.h>
#pragma hdrstop

#include <tchar.h>

#include <stdio.h>

#include "libtool.h"

#include "step3.rh"

//------------------------------------------------------------------------------
// в Win32 линкуется SDK/lib/kAPI2D5bc.lib
// в x64 линкуется SDK/lib64/kAPI2D5bc.a
// ---
#pragma comment(lib, "kAPI2D5bc")

//-------------------------------------------------------------------------------
// Задать идентификатор ресурсов
// ---
extern "C" unsigned int __export __stdcall LIBRARYID()
{
  return IDR_LIBID;
}


//-------------------------------------------------------------------------------
// Описания используемых функций
// ---
void WorkDocument();
void DrawView();
void DrawLayer();
void DrawGroup();
void WorkNameGroup();
void DrawLineSeg();
void DrawArc();
void DrawLine();
void DrawCircle();
void DrawPoint();
void DrawBezier();
void DrawHatch();
void DrawText();


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
extern "C" void __export __stdcall LIBRARYENTRY( unsigned int comm )
{
  if ( comm == 1 )
    WorkDocument();  // Создать документ
  else
  {
    if ( ksGetCurrentDocument( 1 ) ) // Получить активный 2D документ
    {
      switch ( comm ) 
      {
        case 2  : DrawView();      break; // Виды
        case 3  : DrawLayer();     break; // Слои
        case 4  : DrawGroup();     break; // Группы
        case 5  : WorkNameGroup(); break; // Именная группа
        case 6  : DrawLineSeg();   break; // Отрезки
        case 7  : DrawArc();       break; // Дуги
        case 8  : DrawLine();      break; // Линии
        case 9  : DrawCircle();    break; // Окружности
        case 10 : DrawPoint();     break; // Точки
        case 11 : DrawBezier();    break; // Bezier-сплайны
        case 12 : DrawHatch();     break; // Штриховка
        case 13 : DrawText();      break; // Текст
      }
    }
    else
			MessageT( _T("Документ не активизирован или\nне является листом/фрагментом") );
  }
}


//-------------------------------------------------------------------------------
// Работа с документом
// ---
void WorkDocument()
{
	DocumentParamT parDocument; // Структура параметров документа

	lstrcpy( parDocument.fileName, _T("c:\\1.cdw") );         // Имя  файла документа
	lstrcpy( parDocument.comment,  _T("Create document") );   // Комментарий к документу
	lstrcpy( parDocument.author,   _T("User") );              // Автор документа
	parDocument.regim              = 0;                   // Режим ( 0 - видимый, 1 - слепой )
	parDocument.type               = lt_DocSheetStandart; // Тип документа - чертеж стандартный
  // Структура параметров оформления документов ( параметры листа чертежа стандартного формата )
  parDocument.sheet.stPar.format   = 3;                 // Формат листа 0( А0 ) ... 4( А4 )
  parDocument.sheet.stPar.multiply = 1;                 // Кратность формата
  parDocument.sheet.stPar.direct   = 0;                 // Расположение штампа ( 0 - вдоль короткой стороны, 1 - вдоль длинной )
  parDocument.sheet.shtType        = 1;                 // Тип штампа из указанной библиотеки для спецификации ( номер стиля из указанной библиотеки )
  parDocument.sheet.layoutName[0]  = '\0';              // Имя библиотеки оформления (Graphic.lyt) 
  // Создаем документ: лист, формат А3, горизонтально расположенный и с системным штампом 1
  reference rDocument = CreateDocumentT( &parDocument );
 
  /*
  reference rDocument = OpenDocument( "c:\\1.cdw", 1 );
  */
 
	ViewParamT parView; // Структура параметров вида
	memset( &parView, 0, sizeof(parView) );
	parView.x     = 10;                  // Точка привязки вида
	parView.y     = 20;
	parView.scale = 0.5;                 // Масштаб вида
	parView.ang   = 45;                  // Угол поворота вида
	parView.color = RGB( 10, 20, 10 );   // Цвет вида в активном состоянии
	parView.state = stACTIVE;            // Состояние вида
	_tcscpy( parView.name, _T("User view") ); // Имя вида
  // У документа создадим вид с номером 2, масштабом 0.5, под углом 45 гр.
  int number = 2;
	CreateSheetViewT( &parView, &number );
 
  // Создадим слой с номером 5
  Layer( 5 );
  // Отрисовка отрезков
  LineSeg( 20, 10, 40, 10, 1 );
	LineSeg( 40, 10, 40, 30, 1 );
  LineSeg( 40, 30, 20, 30, 1 );
	LineSeg( 20, 30, 20, 10, 1 );
 
  // Получить параметры документа
	GetObjParam( rDocument, &parDocument, sizeof( parDocument ), ALLPARAM_T );
	TCHAR buf[ 255 ];
	_stprintf( buf, _T("type = %d, sheet.stPar.format = %d,\nsheet.stPar.multiply = %d, sheet.stPar.direct = %d,\nfileName = %s,\ncomment = %s,\nauthor = %s"),
					 parDocument.type, parDocument.sheet.stPar.format,
           parDocument.sheet.stPar.multiply, parDocument.sheet.stPar.direct, 
           parDocument.fileName, parDocument.comment, parDocument.author );
	MessageT( buf );

	// Сохраним документ
	SaveDocumentExT( 0, _T(""), 0 );

  /*
  // Закрыть документ
  CloseDocument( rDocument );
  */
}


//-------------------------------------------------------------------------------
// Создать вид
// ---
void DrawView()
{
  ViewParamT parView; // Структура параметров вида
 
  parView.x     = 10;                  // Точка привязки вида
  parView.y     = 20;
  parView.scale = 0.5;                 // Масштаб вида
  parView.ang   = 45;                  // Угол поворота вида
  parView.color = RGB( 10, 20, 10 );   // Цвет вида в активном состоянии
  parView.state = stACTIVE;            // Состояние вида
	_tcscpy( parView.name, _T("User view") ); // Имя вида
  // Создадим вид с номером 5, масштабом 0.5, под углом 45 гр.
  int number = 5;
  reference rView = CreateSheetViewT( &parView, &number );

  // Создание группы объектов, type - тип группы ( 0 - определяет модельный, 1 - временный )
  reference rGroup = NewGroup( 0 );
    LineSeg( 20, 10, 20, 30, 1 );
    LineSeg( 20, 30, 40, 30, 1 );
    LineSeg( 40, 30, 40, 10, 1 );
    LineSeg( 40, 10, 20, 10, 1 );
  EndGroup(); // Завершить создание группы объектов

	MessageT( _T("Добавим вид в группу") );
	// Добавим вид в группу
	if( !AddObjGroup( rGroup, rView ) )
		MessageBoxResult(); // Выдать сообщение об ошибке на экран

	// Повернуть группу на -45 градусов вокруг точки ( 0, 0 )
	RotateObj( rGroup, 0, 0, -45 );

	MessageT( _T("Добавим вид в группу второй раз") );
  // Добавим вид в группу второй раз   
  if( !AddObjGroup( rGroup, rView ) )
    MessageBoxResult(); // Должно быть сообщение о повторном включении объекта в группу ( вид уже включен )
  
  // Получить параметры видa
	GetObjParam( rView, &parView, sizeof( parView ), ALLPARAM_T );
  number = GetViewNumber( rView );
	TCHAR buf[255];
	_stprintf( buf, _T("x = %4.2f, y = %4.2f, scale = %4.2f, ang = %4.2f, color = %x, state = %d, name = %s, number = %d"),
					   parView.x, parView.y, parView.scale, parView.ang, parView.color, parView.state, parView.name, number );
	MessageT( buf );

  // Сделать текущим системный вид ( номер 0 )
  OpenView( 0 );
  
	MessageT( _T("Изменить состояние вида") );
  // Изменить состояние вида ( только чтение )
  int state = stREADONLY;
  SetObjParam( rView, &state, sizeof( state ), VIEW_LAYER_STATE );
}


//-------------------------------------------------------------------------------
// Создать слой
// ---
void DrawLayer()
{
  int number;
	if ( ReadIntT( _T("Введите номер создавоемого слоя"), 1, 0, 255, &number ) )
  {
    // Переопределение текущего слоя, если слоя с заданным номером
    // нет, такой слой создается. Слой становится текущим
    reference rLayer = Layer( number );

    Mtr( 20, 15, 0, 1 ); // Матрица преобразования координат ( 20 по оси OX, 15 по оси OY )
      LineSeg( -10, 0,   10, 0,  1 );
      LineSeg(  10, 0,   10, 20, 1 );
      LineSeg(  10, 20, -10, 20, 1 );
      LineSeg( -10, 20, -10, 0,  1 );
    DeleteMtr();         // Отключение матрицы преобразования координат

    // Подсветить слой
    LightObj( rLayer, 1 );

    // Получить номер слоя по указателю и указатель по номеру
    number = GetLayerNumber( rLayer );
    rLayer = GetLayerReference( number );

		MessageT( _T("Снять выделение слоя") );
    // Снять выделение слоя
    LightObj( rLayer, 0 );

		LayerParamT parLayer; // Структура параметров слоя

    // Получить параметры слоя
		GetObjParam( rLayer, &parLayer, sizeof(parLayer), ALLPARAM_T );
		TCHAR buf [255];
		_stprintf( buf, _T("number = %d, rLayer = %d,\nstate = %d, color = %x, name = %s"),
						 number, rLayer, parLayer.color, parLayer.state, parLayer.name );
		MessageT( buf );

		// Установить параметры слоя
		parLayer.color = RGB( 0, 255, 0 );   // Цвет слоя в активном состоянии
		parLayer.state = stACTIVE;           // Состояние слоя
		_tcscpy( parLayer.name, _T("Зеленый") ); // Имя слоя
    // Параметры текущего слоя изменить нельзя поэтому переключаемся на нулевой слой
    Layer( 0 );

		if ( !SetObjParam( rLayer, &parLayer, sizeof( parLayer ), ALLPARAM_T ) )
      MessageBoxResult(); // Выдать сообщение об ошибке на экран
    else {
      // Получить параметры слоя
			GetObjParam( rLayer, &parLayer, sizeof( parLayer ), ALLPARAM_T );
			_stprintf( buf, _T("number = %d, rLayer = %d,\nstate = %d, color = %x, name = %s"),
             number, rLayer, parLayer.color, parLayer.state, parLayer.name );
			MessageT( buf );
    }

		MessageT( _T("Изменить состояние слоя") );
    // Изменить состояние слоя ( активизировать слой )
    int state = stACTIVE ;
    SetObjParam( rLayer, &state, sizeof( state ), VIEW_LAYER_STATE );
  }
}


//-------------------------------------------------------------------------------
// Работа с группой
// ---
void DrawGroup()
{
  // Создание группы объектов, type - тип группы ( 0 - определяет модельный, 1 - временный )
  reference rGroup = NewGroup( 0 );
    LineSeg( 10, 10, 10, 20, 0 );
  EndGroup(); // Завершить создание группы объектов
 
  // Сдвинуть группу на 10 по оси OX
  MoveObj( rGroup, 10, 0 );
  
  // Повернуть группу на 45 градусов вокруг точки ( 20, 10 )
  RotateObj( rGroup, 20, 10, 45 );

	MessageT( _T("Очистили группу ( объекты исключаются из группы )") );
  // Очистили группу ( объекты исключаются из группы )
  ClearGroup( rGroup );
  
  // Создание отрезка
  reference rLineSeg = LineSeg( 10, 10, 20, 10, 0 );
  
  // Добавить новый объект в группу
  AddObjGroup( rGroup, rLineSeg );

  // Подсветить группу
  LightObj( rGroup, 1 );
 
	MessageT( _T("Снять выделение группы") );
  // Снять выделение группы
  LightObj( rGroup, 0 );
 
  // Удалим  группу ( объекты удалятся тоже )
  DeleteObj( rGroup );
}


//-------------------------------------------------------------------------------
// Работа с именнованной группой
// ---
void WorkNameGroup()
{
  // Создание группы объектов, type - тип группы ( 0 - определяет модельный, 1 - временный )
  reference rGroup = NewGroup( 0 );
    LineSeg( 20, 20, 40, 20, 1 );
    LineSeg( 40, 20, 40, 40, 1 );
    LineSeg( 40, 40, 20, 40, 1 );
    LineSeg( 20, 40, 20, 20, 1 );
  EndGroup(); // Завершить создание группы объектов
 
  // Сохранить группу объектов в модели с указанным именем 
  // Группа автоматически сохраняется в чертеже при его записи
  // В противном случае группа действительна только в текущем сеансе работы
  // Если указатель группы равен нулю, то сохраняется группа селектирования
  // КОМПАС-ГРАФИК (выделенные объекты чертежа).
	if ( !SaveGroupT(  rGroup, _T("Group") ) )
    exit( EXIT_SUCCESS );
    
	rGroup = GetGroupT( _T("Group") );
  if ( !rGroup )
    exit( EXIT_SUCCESS );
 
  // Создание окружности
  reference rCircle = Circle( 30, 30, 10, 1 );
 
  // Добавить новый объект в группу
  AddObjGroup( rGroup, rCircle );
 
  LightObj( rGroup, 1 );
	MessageT( _T("Был добавлен объект в именную группу") );
  LightObj( rGroup, 0 );
 
  // Исключить объект из группы
  ExcludeObjGroup( rGroup, rCircle );
 
  LightObj( rGroup, 1 );
	MessageT( _T("Объект был исключен из именной группы") );
  LightObj( rGroup, 0 );
}


//-------------------------------------------------------------------------------
// Создать отрезок
// ---
void DrawLineSeg()
{
  Mtr( 30, 20, 45, 1 ); // Матрица преобразования координат ( 30 по оси OX, 25 по оси OY, поворот на 45 градусов )
    // Создание отрезка
    reference rLineSeg = LineSeg( 30, 20, // Координаты начальной точки
                                  60, 20, // Координаты конечной точки
                                  1 );    // Стиль линии ( 1 - основная линия, 2 - тонкая линия, 3 - осевая линия,
                                          // 4 - штриховая линия, 5 - для линии обрыва, 6 - вспомогательная линия,
                                          // 7 - утолщенная, 8 - штрих-пунктирная линия с двумя точками,
                                          // 9 - штриховая толстая линия, 10 - осевая толстая линия,
                                          // 11 - тонкая линия, включаемая в штриховку )
  DeleteMtr(); // Отключение матрицы преобразования координат
  
  LineSegParam parLineSeg; // Структура параметров отрезка

  // Получить параметры отрезка
	GetObjParam( rLineSeg, &parLineSeg, sizeof( parLineSeg ), ALLPARAM_T );
	TCHAR buf [255];
	_stprintf( buf, _T("x1 = %4.2f, y1 = %4.2f, x2 = %4.2f, y2 = %4.2f, style = %d"),
					 parLineSeg.x1, parLineSeg.y1, parLineSeg.x2, parLineSeg.y2, parLineSeg.style );
	MessageT( buf );

  // Задать параметры отрезка
  parLineSeg.x2    = 30; // Координаты конечной точки
  parLineSeg.y2    = 60;
  parLineSeg.style = 2;  // Стиль линии
  
  // Заменить параметры отрезка
	if ( !SetObjParam( rLineSeg, &parLineSeg, sizeof( parLineSeg ), ALLPARAM_T ) )
    MessageBoxResult(); // Выдать сообщение об ошибке на экран   
}


//-------------------------------------------------------------------------------
// Создать дугу
// ---
void DrawArc()
{
  Mtr( 10, 10, 0, 1 ); // Матрица преобразования координат ( 10 по оси OX, 10 по оси OY )
    // Создать дугу по углам
    reference rArcByAngle = ArcByAngle( 30, 20,  // Координаты центра дуги
                                        20,      // Радиус
                                        45, 135, // Углы начальной и конечной узловых точек в градусах
                                        1,       // Направление дуги ( +1 - против часовой стрелки, -1 - по часовой стрелке )
                                        1 );     // Cтиль линии ( 1 - основная, 2 - тонкая, 3 - осевая, 4 - штриховая, 
                                                 // 5 - волнистая, 6 - утолщенная, 7 - штрихпунктирная с двумя точками, 
                                                 // 8 - осевая основная, 9 - штриховая основная, 10 - осевая толстая,
                                                 // 11 - тонкая, включаемая в штриховку )
  DeleteMtr(); // Отключение матрицы преобразования координат
   
  ArcParam parArc; // Структура параметров дуги окружности по центру, радиусу и углам
  
  // Получить параметры дуги
	GetObjParam( rArcByAngle, &parArc, sizeof( parArc ), ALLPARAM_T );
	TCHAR buf [255];
	_stprintf( buf, _T("xc = %4.2f, yc = %4.2f, rad = %4.2f,\nang1 = %4.2f, ang2 = %4.2f, dir = %d, style = %d"),
           parArc.xc, parArc.yc, parArc.rad, parArc.ang1, parArc.ang2, parArc.dir, parArc.style );
	MessageT( buf );
  
  ArcParam1 parArc1; // Структура параметров дуги по точкам
 
  // Задать параметры дуги по точкам
  parArc1.xc    = 40; // Координаты центра дуги
  parArc1.yc    = 30;
  parArc1.rad   = 10; // Радиус
  parArc1.x1    = 50; // Начальная точка дуги
  parArc1.y1    = 30;
  parArc1.x2    = 40; // Конечная точка дуги
  parArc1.y2    = 20; 
  parArc1.dir   = 1;  // Направление построения дуги
  parArc1.style = 2;  // Cтиль линии

  // Заменить параметры дуги
	if ( !SetObjParam( rArcByAngle, &parArc1, sizeof( parArc1 ), POINT_ARC_PARAM ) )
    MessageBoxResult(); // Выдать сообщение об ошибке на экран   
}


//-------------------------------------------------------------------------------
// Создать вспомогательную линию
// ---
void DrawLine()
{
  Mtr( 0, 0, 45, 1 ); // Матрица преобразования координат ( поворот на 45 градусов )
    // Создать вспомогательную линию
    reference rLine = Line( 30, 20, // Координаты точки
                            0 );    // Угол наклона прямой
  DeleteMtr(); // Отключение матрицы преобразования координат

  LineParam parLine; // Структура параметров вспомогательной прямой
 
  // Взять параметры вспомогательной линии
	GetObjParam( rLine, &parLine, sizeof( parLine ), ALLPARAM_T );
	TCHAR buf [255];
	_stprintf( buf, _T("x = %4.2f, y = %4.2f, ang = %4.2f"),
           parLine.x, parLine.y, parLine.ang );
	MessageT( buf );
 
  // Задать параметры вспомогательной линии
  parLine.x   = 0;  // Координаты точки
  parLine.y   = 0; 
  parLine.ang = 90; // Угол наклона прямой
 
  // Заменить параметры вспомогательной линии
	if ( !SetObjParam( rLine, &parLine, sizeof( parLine ), ALLPARAM_T ) )
    MessageBoxResult(); // Выдать сообщение об ошибке на экран   
}


//-------------------------------------------------------------------------------
// Создать окружность
// ---
void DrawCircle()
{
  Mtr( 0, 0, 0, 2 ); // Матрица преобразования координат ( маштаб 2:1 )
    // Создать окружность
    reference rCircle = Circle( 30, 20, // Координаты центра окружности
                                10,     // Радиус окружности
                                1 );    // Cтиль линии ( 1 - основная, 2 - тонкая, 3 - осевая, 4 - штриховая, 
                                        // 5 - волнистая, 6 - утолщенная, 7 - штрихпунктирная с двумя точками, 
                                        // 8 - осевая основная, 9 - штриховая основная, 10 - осевая толстая,
                                        // 11 - тонкая, включаемая в штриховку )
  DeleteMtr(); // Отключение матрицы преобразования координат
 
  CircleParam parCircle; // Структура параметров окружности
  
  // Взять параметры олружности
	GetObjParam( rCircle, &parCircle, sizeof( parCircle ), ALLPARAM_T );
	TCHAR buf [255];
	_stprintf( buf, _T("xc = %4.2f, yc = %4.2f, rad = %4.2f, style = %d"),
           parCircle.xc, parCircle.yc, parCircle.rad, parCircle.style );
	MessageT( buf );
 
  // Задать параметры окружности
  parCircle.xc    = 0;  // Координаты центра окружности
  parCircle.yc    = 0;
  parCircle.rad   = 20; // Радиус окружности
  parCircle.style = 2;  // Cтиль линии
  
  // Заменить параметры окружности
	if ( !SetObjParam( rCircle, &parCircle, sizeof( parCircle ), ALLPARAM_T ) )
    MessageBoxResult(); // Выдать сообщение об ошибке на экран   
}


//-------------------------------------------------------------------------------
// Cоздать точку
// ---
void DrawPoint()
{
  Mtr( 10, 10, 0, 1 ); // Матрица преобразования координат ( 10 по оси OX, 10 по оси OY )
  // Создать точку
  reference rPoint = Point( 30, 40, // Координаты точки
                            0 );    // Cтиль отрисовки точки ( 0 - точка, 1 - крестик, 2 - х-точка,
                                    // 3 - квадрат, 4 - треугольник, 5 - окружность, 6 - звезда,
                                    // 7 - перечеркнутый квадрат, 8 - утолщенный плюс )
    Point( 40,  40, 1 );
    Point( 50,  40, 2 );
    Point( 60,  40, 3 );
    Point( 70,  40, 4 );
    Point( 80,  40, 5 );
    Point( 90,  40, 6 );
    Point( 100, 40, 7 );
  DeleteMtr(); // Отключение матрицы преобразования координат
 
  PointParam parPoint; // Структура параметров точки
  
  // Взять параметры точки
	GetObjParam( rPoint, &parPoint, sizeof( parPoint ), ALLPARAM_T );
	TCHAR buf [255];
	_stprintf( buf, _T("x = %4.2f y = %4.2f style = %d"),
           parPoint.x, parPoint.y, parPoint.style );
	MessageT( buf );
 
  // Задать параметры окружности 
  parPoint.x     = 20; // Координаты точки
  parPoint.y     = 30; 
  parPoint.style = 7;  // Cтиль отрисовки точки
 
  // Заменить параметры точки
	if ( !SetObjParam( rPoint, &parPoint, sizeof( parPoint ), ALLPARAM_T ) )
		MessageBoxResult(); // Выдать сообщение об ошибке на экран
}


//-------------------------------------------------------------------------------
// Создать Bezier сплайн
// ---
void DrawBezier()
{
  // Координаты точек сплайна
  double x[] = { 0, 20, 50, 70, 100, 50 };
  double y[] = { 0, 20, 10, 20, 0,  -50 };
 
  // Создать Bezier сплайн
  Bezier( 0,   // Признак замкнутости кривой ( 0 - не замкнута, 1 - замкнута )
          1 ); // Cтиль линии ( 1 - основная, 2 - тонкая, 3 - осевая, 4 - штриховая, 
               // 5 - волнистая, 6 - утолщенная, 7 - штрихпунктирная с двумя точками, 
               // 8 - осевая основная, 9 - штриховая основная, 10 - осевая толстая,
               // 11 - тонкая, включаемая в штриховку )
    for ( int i = 0; i < 5; i++ )
      Point( x[i], y[i], 0 ); // Точки входящие в кривую Безье
  reference rBezier = EndObj(); // Функция EndObj возвращает указатель на созданный объект кривой Безье
  
  BezierParam parBezier; // Структура параметров кривой Безье
  
  // Взять параметры Bezier сплайна
  parBezier.pMathPoint = CreateArray( POINT_ARR, 0 ); // Создать массив для хранения точек кривой Безье
	GetObjParam( rBezier, &parBezier, sizeof( parBezier ), ALLPARAM_T );
  // Количество элементов в массиве
  int count = GetArrayCount( parBezier.pMathPoint );
	TCHAR buf [255];
	_stprintf( buf, _T("count = %d, closed = %d, style = %d"),
                 count, parBezier.closed, parBezier.style );
	MessageT( buf );
  
  // Взять точки кривой Безье
  MathPointParam parMathPoint; // Структура параметров математической точки
  
  // Цикл по точкам кривой Безье
  for ( int i = 0; i < count; i++ )
  {
    // Получить значение элемента массива
    GetArrayItem( parBezier.pMathPoint, i, &parMathPoint, sizeof( parMathPoint ) );
		_stprintf( buf, _T("x[%d] = %4.2f, y[%d] = %4.2f"),
             i, parMathPoint.x, i, parMathPoint.y );
		MessageT( buf );
  }
 
  // Задать параметры кривой Безье   
  ClearArray( parBezier.pMathPoint ); // Очистим массив для заполнения его новыми точками
  // Подставим свои значения в массив точек
  for ( int i = 0; i < 6; i++ )
  {
    parMathPoint.x = x[i];
    parMathPoint.y = y[i] + 10;
    // Добавим точку в массив, элемент добавляется в конец массива
    AddArrayItem( parBezier.pMathPoint, -1, &parMathPoint, sizeof( parMathPoint ) );
  }
  parBezier.style = 2;  // Cтиль линии
  parBezier.closed = 1; // Признак замкнутости кривой ( 0 - не замкнута, 1 - замкнута )
 
  // Заменить параметры Bezier сплайна
	if ( !SetObjParam( rBezier, &parBezier, sizeof( parBezier ), ALLPARAM_T ) )
    MessageBoxResult(); // Выдать сообщение об ошибке на экран   
     
  DeleteArray( parBezier.pMathPoint ); // Удалить массив точек кривой Безье
}


//-------------------------------------------------------------------------------
// Создать штриховку
// ---
void DrawHatch()
{
  // Создать заштрихованный квадрат
  Mtr( 30, 20, 0, 0.5 ); // Матрица преобразования координат ( 30 по оси OX, 20 по оси OY, маштаб 1:2 )
    // Стороны квадрата
    LineSeg ( 20, 30, 70, 30, 2 );
    LineSeg ( 70, 30, 70, 80, 2 );
    LineSeg ( 70, 80, 20, 80, 2 );
    LineSeg ( 20, 80, 20, 30, 2 );
    // Штриховка квадрата
    Hatch( 0,      // Стиль штриховки ( 0 - металл, 1 - неметалл, 2 - дерево, 3 - камень естественный,
                   // 4 - керамика, 5 - бетон, 6 - стекло, 7 - жидкость, 8 - естественный грунт,
                   // 9 - насыпной грунт, 10 - камень искусственный, 11 - железобетон,
                   // 12 - напряженный железобетон, 13 - дерево в продольном сечении, 14 - песок )
           45,     // Угол штриховки
           2,      // Шаг штриховки
           0,      // Ширина полосы штриховки ( 0 - штриховать всю область )
           0, 0 ); // Базовая точка 
		  LineSeg( 20, 30, 70, 30, 2 ); // Геометрические примитивы определяют границы штриховки
      LineSeg( 70, 30, 70, 80, 2 );
      LineSeg( 70, 80, 20, 80, 2 );
      LineSeg( 20, 80, 20, 30, 2 );
    reference rHatch = EndObj(); // Функция EndObj возвращает указатель на объект Штриховка
  DeleteMtr(); // Отключение матрицы преобразования координат
   
	HatchParam parHatch; // Структура параметров штриховки
   
  // Взять параметры штриховки
	GetObjParam( rHatch, &parHatch, sizeof( parHatch ), ALLPARAM_T );
	TCHAR buf [255];
	_stprintf( buf, _T("style = %d, ang = %4.2f, step = %4.2f\nwidth = %4.2f, x = %4.2f, y = %4.2f"),
           parHatch.style, parHatch.ang, parHatch.step, parHatch.width, parHatch.x, parHatch.y );
	MessageT( buf );
  
  Mtr( 0, 0, 0, 2 ); // Матрица преобразования координат ( маштаб 2:1 )
    // Задать параметры штриховки
    parHatch.x = 0.8;
    // Заменить параметры штриховки
		if ( !SetObjParam( rHatch, &parHatch, sizeof( parHatch ), ALLPARAM_T ) )
      MessageBoxResult(); // Выдать сообщение об ошибке на экран   
  DeleteMtr(); // Отключение матрицы преобразования координат
}


//-------------------------------------------------------------------------------
// Вывод параметров строки
// ---
void PrintTextLine( const TextLineParam & parTextLine )
{
	TCHAR buf[255];
	_stprintf( buf, _T("style = %d"), parTextLine.style );
	MessageT( buf );
 
	TextItemParamT parTextItem; // Структура параметров компоненты строки текста
  
  // Количество элементов в массиве
  int count = GetArrayCount( parTextLine.pTextItem );
  
  // Цикл по компонентам строки
	for ( int i = 0; i < count; i++ )
  {
    // Получить значение элемента массива
    GetArrayItem( parTextLine.pTextItem, i, &parTextItem, sizeof( parTextItem ) );
		_stprintf( buf, _T("i = %d, font.height = %4.2f, s = %s,\nfont.fontName = %s"),
             i, parTextItem.font.height, parTextItem.s, parTextItem.font.fontName );
		MessageT( buf );
  }
}


//-------------------------------------------------------------------------------
// Вывод параметров текста
// ---
void PrintTextPar( const TextParam & parText )
{
	TCHAR buf[255];
	_stprintf( buf, _T("hFormat = %d, vFormat = %d, height = %4.2f, width = %4.2f,\nx = %4.2f, y = %4.2f, ang = %4.2f"),
           parText.par.hFormat, parText.par.vFormat, parText.par.height, parText.par.width, parText.par.x, parText.par.y, parText.par.ang );
	MessageT( buf );

	TextLineParam parTextLine; // Структура параметров строки текста
  
  // Количество элементов в массиве
  int count = GetArrayCount( parText.pTextLine );
  
  // Цикл по строкам текста
  for ( int i = 0; i < count; i++ )
  {
		// Получить значение элемента массива
    GetArrayItem( parText.pTextLine, i, &parTextLine, sizeof( parTextLine ) );
    // Вывод параметров строки
    PrintTextLine( parTextLine );
  }
}


//-------------------------------------------------------------------------------
// Текст
// ---
void DrawText()
{
	ParagraphParam parParagraph; // Структура параметров параграфа

  // Задать параметры параграфа
  parParagraph.style   = 0;  // Номер стиля текста (0 - стиль по умолчанию,
                             // 1 - обычный текст, 2 - текст для технических требований,
                             // 3 - текст размерной надписи, 4 - текст в обозначении шероховатости,
                             // 5 - текст на позиционной линии-выноске, 6 - текст над\под полкой линии-выноски,
                             // 7 - текст на ответвлении линии-выноски, 8 - текст в обозначении допуска формы,
                             // 9 - текст для заголовка таблицы, 10 - текст для ячейки таблицы,
                             // 11 - текст для линии разреза, 12 - текст для стрелки направления взгляда,
                             // 13 - текст в обозначении неуказанной шероховатости,
                             // 14 - текст в обозначении изменения )
  parParagraph.x       = 30; // Координаты точки привязки текста
  parParagraph.y       = 30;
  parParagraph.ang     = 0;  // Угол наклона текста
  parParagraph.hFormat = 0;  // Признак горизонтального форматирования ( 0 - нет форматирования,
                             // 1 - сужение текста, 2 - перенос на другую строку )
  parParagraph.vFormat = 0;  // признак вертикального форматирования ( 0 - нет форматирования,
                             // 1-изменение шага строк )
  parParagraph.height  = 25; // Высота блока форматирования
  parParagraph.width   = 20; // Ширина блока форматирования

  // Параграфом называется автоматически форматируемый блок текста
  Paragraph( &parParagraph );
    // Снятие наклона, по умолчанию включен
		TextLineT( ITALIC_OFF, 0, 0, _T("") );
    // Пример задания дроби
    // Задание подстроки параграфа текста
		TextLineT( NEW_LINE,    // Значения свойств, устанавливаемые двоичными флагами
              0,           // Тип свойства
              0,           // Указатель на значение свойства
							_T("Дробь ") );  // Строка
    // Числитель, наклон, высота дроби в 1.5 раза меньше высоты текста
    int fraction = 2; // Значение свойства FRACTION_TYPE
		TextLineT( NUMERATOR|ITALIC_ON, FRACTION_TYPE, &fraction, _T("111") );
    // Знаменатель, утолщение
		TextLineT( DENOMINATOR|BOLD_ON, 0, 0, _T("222") );
    // Конец дроби, снятие утолщения, снятие наклона и текст после дроби
		TextLineT( END_FRACTION|BOLD_OFF|ITALIC_OFF, 0, 0, _T(" 333") );

    // Пример задания дроби, нижнего и верхнего отклонения
		TextLineT( NEW_LINE, 0, 0, _T("Дробь и отклонения ") );
		// Числитель, наклон
		TextLineT( NUMERATOR|ITALIC_ON, 0, 0, _T("111 ") );
		// Базвая строка для отклонения
		TextLineT( S_BASE, 0, 0, _T("222") );
		// Верхнее отклонение
		TextLineT( S_UPPER_INDEX, 0, 0, _T("Верх") );
		// Нижнее отклонение
		TextLineT( S_LOWER_INDEX, 0, 0, _T("Низ") );
		// Конец отклонения
		TextLineT( S_END, 0, 0, _T(" 333") );
		// Знаменатель, утолщение
		TextLineT( DENOMINATOR, 0, 0, _T("444") );
		// Конец дроби, снятие утолщения, снятие наклона и текст после дроби
		TextLineT( END_FRACTION|BOLD_OFF|ITALIC_OFF, 0, 0, _T(" 555") );

    // Пример задания спецсимвола
		TextLineT( NEW_LINE, 0, 0, _T("Спецсимвол ") );
		int symbol = 65; // Номер спецзнака - шероховатость
		// Спецзнак
		TextLineT( SPECIAL_SYMBOL, SPECIAL, &symbol, _T("") );
		// Конец спецсимвола и текст после спецзнака
		TextLineT( SPECIAL_SYMBOL_END, 0, 0, _T(" 111") );

		// Пример задания символа из сушествующего шрифта
		TextLineT( NEW_LINE, 0, 0, _T("Шрифт Arial ") );
		TCHAR name[10];
		_tcscpy( name, _T("Arial") ); // Название шрифта - Arial
    unsigned int ch = 64; // Номер символа из шрифта - @
    // Задания символа из Arial
		TextLineT( FONT_SYMBOL, FONT_NAME, name, ( TCHAR * ) ch );

  // Описание параграфа заканчивается функцией EndObj, возвращающей указатель на созданный объект
  reference rParagraph = EndObj();

  /*
  TextParam parText; // Структура параметров текста

  // Возьмем параметры текста
	GetObjParam( rParagraph, &parText, sizeof( parText ), ALLPARAM_T );
	// Вывод параметров текста
  PrintTextPar( parText );
  */

	TextLineParam parTextLine; // Структура параметров строки текста

  // Возьмем параметры 1-ой строки ( индекс 0 )
  GetObjParam( rParagraph, &parTextLine, sizeof( parTextLine ), 0 );
  // Вывод параметров строки
  PrintTextLine( parTextLine );

	if ( YesNoT( _T("Изменять параметры текста ?") ) == 1 )
  {
    TextItemParam parTextItem; // Структура параметров компоненты строки текста

    // У первой строки включим ITALIC и BOLD и меняем цвет
    GetArrayItem( parTextLine.pTextItem, 0, &parTextItem, sizeof( parTextItem ) );
    parTextItem.font.bitVector = parTextItem.font.bitVector | ITALIC_ON | BOLD_ON; // Значения свойств, устанавливаемые двоичными флагами
    parTextItem.font.color = RGB ( 0, 255, 0 ); // Цвет
    SetArrayItem( parTextLine.pTextItem, 0, &parTextItem, sizeof( parTextItem ) );
    // Заменим у текста первую строку
    SetObjParam( rParagraph, &parTextLine, sizeof( parTextLine ), 0 );
    // Возьмем параметры 1-ой строки ( индекс 0 )
    GetObjParam( rParagraph, &parTextLine, sizeof( parTextLine ), 0 );
    // Вывод параметров строки
    PrintTextLine( parTextLine );
  }
}
