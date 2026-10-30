# ksDrawBitmapEx2 - Отрисовать BMP с идентификатором bmpID в заданном окне(hWindow)

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksdrawkompasdocument.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](ag163509.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [ksDrawBitmapEx](ksdrawbitmapex.html).

Синтаксис Automation:

long ksDrawBitmapEx2(long HWindow, long bmpID, VARIANT hInst);

Входные параметры:

Hwindow | \- дескриптор окна, в котором нужно отрисовать BITMAP-слайд,  
---|---  
sldID | \- идентификатор BITMAP-слайда в файле ресурсов,  
hInst | \- hInstance библиотеки, в которой расположен слайд.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

HINSTANCE библиотеки нужно передать через VARIANT, как VT_I4 в Win32 и VT_I8 в x64. Для правильного формирования _variant_t HINSTANCE нужно передавать его через приведение к (LONG_PTR).

В библиотеках, использующих автоматизацию, рекомендуется использовать данную функцию вместо [KompasObject::ksDrawBitmapEx](kompasobject_ksdrawbitmapex.html).

Подразделы:

(отсутствуют)
