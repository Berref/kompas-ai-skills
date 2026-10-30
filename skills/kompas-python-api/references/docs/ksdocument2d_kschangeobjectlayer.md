# ksChangeObjectLayer - Изменить слой одного объекта

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Работа со слоями ](bt1732273.html) |  Scroll [ [ [ ](ksdocument2d_ksgetlayernumber.html "К следующему разделу")](bt1732273.html "На уровень выше")](bt1732273.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ChangeObjectLayer](changeobjectlayer.html).

Синтаксис Automation:

long ksChangeObjectLayer (long Reference,

long number);

Входные параметры:

Reference | \- указатель на объект,  
---|---  
number | \- номер слоя, на который переносится объект.  
  
Возвращаемое значение:

-1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Слой, на который переносится объект, должен существовать и быть доступным для редактирования (не фоновым и не выключенным).

Подразделы:

(отсутствуют)
