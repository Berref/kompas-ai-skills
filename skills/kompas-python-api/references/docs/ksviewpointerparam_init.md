# Init - Инициализировать параметры

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров обозначений ](ch1786244.html) > [Стрелка направления взгляда (Интерфейс ksViewPointerParam) ](ksviewpointerparam.html) > [ksViewPointerParam - методы ](ksviewpointerparam_methods.html) |  Scroll [ [ [ ](ksviewpointerparam_setptextline.html "К следующему разделу")](ksviewpointerparam_methods.html "На уровень выше")](ksviewpointerparam_getptextline.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksviewpointerparam.html)

Синтаксис Automation:

BOOL Init();

Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Примечания:

1\. Метод обнуляет все параметры.

2\. Свойство [ksViewPointerParam::type](ksviewpointerparam_type.html) = 1.

3\. Создается динамический массив pTextItem типа TEXT_ITEM_ARR.

Подразделы:

(отсутствуют)
