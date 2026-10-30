# ksCalcRasterScaleW - Рассчитать масштаб для вставки растра в прямоугольник заданных габаритов (Unicode)

[API экспортных функций](export_function.html) > [Редактирование графических объектов ](cn1712096.html) > [Функции редактирования объектов чертежа ](draft_edit_fncts_common.html) |  Scroll [ [ [ ](kschangeobjectinlibrequest.html "К следующему разделу")](draft_edit_fncts_common.html "На уровень выше")](kscalcrasterscale.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksCalcRasterScale](ksdocument2d_kscalcrasterscale.html).

Синтаксис:

double LIB_FUNC ksCalcRasterScaleW (LPWSTR fileName, double w, double h);

Входные параметры:

fileName | \- полный путь к файлу,  
---|---  
w | \- ширина габаритного прямоугольника,  
h | \- высота габаритного прямоугольника.  
  
Возвращаемое значение:

значение масштаба | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

При использовании ANSI следует использовать функцию [ksCalcRasterScale](kscalcrasterscale.html).

Подразделы:

(отсутствуют)
