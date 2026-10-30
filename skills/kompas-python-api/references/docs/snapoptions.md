# SnapOptions - Структура параметров привязок в графическом документе

[Структуры параметров и константы](3d_define.html) > [Структуры параметров документов ](bk1829760.html) |  Scroll [ [ [ ](structstandartsheet.html "К следующему разделу")](bk1829760.html "На уровень выше")](structsheetsize.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksSnapOptions](kssnapoptions.html).

struct | SnapOptions | Глобальные привязки  
---|---|---  
unsigned char | nearestPoint | Ближайшая точка  
unsigned char | nearestMiddle | Середина  
unsigned char | intersect | Пересечение  
unsigned char | tangentToCurve | Касание  
unsigned char | normalToCurve | Нормаль  
unsigned char | grid | По сетке  
unsigned char | xyAlign | Выравнивание  
unsigned char | angSnap | Угловая привязка  
unsigned char | pointOnCurve | Точка на кривой  
unsigned int | commonOpt | Общие настройки привязок: динамически отслеживать, отображать текст, с учетом фоновых слоев, подавить привязки  
double | angleStep | Угловой шаг для привязок  
unsigned char | localSnap | Tип локальной привязки  
  
[Типы локальной привязки...](stypes.html)

[Общие настройки привязок...](sstypes.html)

Подразделы:

(отсутствуют)
