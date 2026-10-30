# PointArraw - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
{

Macro (0);

LineSeg (50, 100, 100, 100, 2);

PointArraw (50, 100, 0 /*ang*/, 1 /* стрелка изнутри*/);

PointArraw (100, 100, 180/*ang*/, 1 /* стрелка изнутри*/);

reference pMacro = EndObj();

LightObj (pMacro, 1);

Message ("Имитация размерной линии");

LightObj (pMacro, 0);

}
