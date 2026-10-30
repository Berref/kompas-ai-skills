# ksLightObj - Выделить объект цветом ("подсветить" объект)

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Редактирование графических объектов ](bt1730357.html) |  Scroll [ [ [ ](ksdocument2d_ksundocontainer.html "К следующему разделу")](bt1730357.html "На уровень выше")](ksdocument2d_ksexistobj.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [LightObj](lightobj.html).

Синтаксис Automation:

long ksLightObj (long ref,

short ligth);

Входные параметры:

ref | \- указатель на объект,  
---|---  
ligth | \- режим подсветки: 1 - установить выделение, 0 - снять выделение.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
