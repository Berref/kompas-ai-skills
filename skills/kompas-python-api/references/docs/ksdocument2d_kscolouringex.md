# ksColouringEx - Создать фоновую заливку цветом

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) |  Scroll [ [ [ ](ksdocument2d_kscommandwindow.html "К следующему разделу")](ksdocument2d_methods.html "На уровень выше")](ksdocument2d_kschangeobjectsorder.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksColouringEx](kscolouringex.html).

Синтаксис Automation:

long ksColouringEx (long color, reference group);

Входные параметры:

color | \- цвет заливки,  
---|---  
group | \- группа, образующая границу заливки.  
  
Возвращаемое значение:

указатель на заливку | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Если color = -1 или 0xFFFFFFFF,то создается заливка цветом фона документа.

Подразделы:

(отсутствуют)
