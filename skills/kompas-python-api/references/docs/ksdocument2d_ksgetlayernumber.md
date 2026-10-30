# ksGetLayerNumber - Получить номер слоя

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Работа со слоями ](bt1732273.html) |  Scroll [ [ [ ](ksdocument2d_ksgetlayerreference.html "К следующему разделу")](bt1732273.html "На уровень выше")](ksdocument2d_kschangeobjectlayer.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [GetLayerNumber](getlayernumber.html).

Синтаксис Automation:

long ksGetLayerNumber (long Reference);

Входной параметр:

Reference | \- указатель на слой.  
---|---  
  
Возвращаемое значение:

номер слоя | \- в случае удачного завершения,  
---|---  
-1 | \- в случае неудачи.  
  
Примечания:

1\. Системный слой имеет номер 0.

2\. Если Reference - объект слоя, возвращается номер слоя этого объекта.

Подразделы:

(отсутствуют)
