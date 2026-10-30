# RasterFormatParam - Структура параметров записи в растровый формат

[Структуры параметров и константы](3d_define.html) > [Структуры параметров документов ](bk1829760.html) |  Scroll [ [ [ ](structrasterformatparamw.html "К следующему разделу")](bk1829760.html "На уровень выше")](structplacementparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksRasterFormatParam.](ksrasterformatparam.html)

unsigned char | format | формат растра  
---|---|---  
unsigned char | colorBPP | глубина цвета (бит на пиксел)  
unsigned char | greyScale | признак сохранения в оттенках серого (0 - цветной растр, >0 - оттенки серого)  
int | extResolution | разрешение растра (0 - текущее разрешение)  
double | extScale | масштаб  
unsigned char | colorType | цвет вывода объектов  
unsigned char | onlyThinLine | признак вывода всех линий тонкими (0 - установленные для объектов толщины линий, >0 - выводит все тонкими линиями)  
char | Pages [MAX_TEXT_LENGTH] | список диапазонов выводимых страниц в формате "beg1-end1, beg2-end2, beg3-end3, ..."  
unsigned char | rangeIndex | признак выбора стороны страниц (0 - все, 1- нечетные, 2 - четные),  
unsigned char | multiPageOutput | признак сохранения всех листов в одном файле (0 - сохранять листы в отдельных файлах, >0 сохранять все листы в одном файле) (признак используется только для формата TIFF)  
  
[Форматы растра...](lrasterformats.html)

[Цвета вывода объектов...](lobjcolors.html)

[Глубина цвета растра...](lpalettes.html)

Примечание.

При использовании Unicode следует использовать структуру параметров [RasterFormatParamW](structrasterformatparamw.html).

Подразделы:

(отсутствуют)
