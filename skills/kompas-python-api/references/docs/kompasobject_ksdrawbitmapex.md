# ksDrawBitmapEx - Отрисовать растровый слайд в заданном окне

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) > [Методы вывода на экран ](ag91931.html) |  Scroll [ [ [ ](kompasobject_ksdrawslide.html "К следующему разделу")](ag91931.html "На уровень выше")](kompasobject_ksdrawbitmap.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html).

Аналог данного метода при использовании API экспортных функций - [ksDrawBitmapEx](ksdrawbitmapex.html).

Синтаксис Automation:

long ksDrawBitmapEx (long HWindow, long sldID, long hInst);

Входные параметры:

Hwindow | \- дескриптор окна, в котором нужно отрисовать BITMAP-слайд,  
---|---  
sldID | \- идентификатор BITMAP-слайда в файле ресурсов,  
hInst | \- hInstance текущей библиотеки или NULL, если она одна.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Функция устарела. Использование данной функции может привести к ошибке в библиотеке, собранной с конфигурацией x64.

Рекомендуется использовать функцию [KompasObject::ksDrawBitmapEx2](kompasobject_ksdrawbitmapex2.html).

Подразделы:

(отсутствуют)
