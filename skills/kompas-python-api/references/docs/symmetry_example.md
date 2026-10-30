# Symmetry - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//-------------------------------------------------------------------------------

// Симметрия точки

// ---

void SymmetryPoint()

{

double px=10, py=10;

double

os_x1 = 50, os_y1 = 50,

os_x2 = 60, os_y2 = 50;

// Отрисовка точки

Point( px, py, 0 );

// Отрисовка отрезка

LineSeg( os_x1, os_y1, os_x2, os_y2, 1 );

double s_px, s_py; // Результат симметрии точки

// Получить координаты точки, симметричной относительно заданной оси

Symmetry( px, py, // Координаты точки

os_x1, os_y1, // Начальная точка оси

os_x2, os_y2, // Конечная точка оси

&s_px, &s_py ); // Результат симметрии

// Отрисовка результирующей точки

Point( s_px, s_py, 1 );

// Результат симметрии

TCHAR buf[255];

_stprintf_s( buf, _T("x = %4.2f, y = %4.2f"), s_px, s_py );

MessageT( buf );

//---- работа с в режиме преобразования координат

ksMtr(100,100,0,1,1);

// Отрисовка точки

Point( px, py, 0 );

// Отрисовка отрезка

LineSeg( os_x1, os_y1, os_x2, os_y2, 1 );

double lcs_px, lcs_py;

ksPointFromMtr( px, py, &lcs_px, &lcs_py );

Symmetry( lcs_px, lcs_py, // Координаты точки

os_x1, os_y1, // Начальная точка оси

os_x2, os_y2, // Конечная точка оси

&s_px, &s_py ); // Результат симметрии

// Отрисовка результирующей точки

ksPointIntoMtr(s_px, s_py, &lcs_px, &lcs_py );

Point( lcs_px, lcs_py, 1 );

DeleteMtr();

_stprintf_s( buf, _T("x = %4.2f, y = %4.2f"), lcs_px, lcs_py );

MessageT( buf );

}
