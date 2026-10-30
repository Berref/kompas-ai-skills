# SetDimensionLayoutScaling - Установить признак масштабирования аннотационных объектов вида

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров формата и компоновки чертежа ](ce1717197.html) > [Интерфейс параметров ассоциативного вида (Интерфейс ksAssociationViewParam) ](ksassociationviewparam.html) > [ksAssociationViewParam - методы ](ksassociationviewparam_methods.html) |  Scroll [ [ [ ](ksassociationviewparam_viewtype.html "К следующему разделу")](ksassociationviewparam_methods.html "На уровень выше")](ksassociationviewparam_init.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksassociationviewparam.html)

Синтаксис Automation:

BOOL SetDimensionLayoutScaling(BOOL scaling);

Входной параметр:

scaling | TRUE | \- масштабировать аннотационные объекты вида,  
---|---|---  
FALSE | \- не масштабировать объекты.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Используется только для изменения параметров вида [ksDocument2D::ksSetObjParam](ksdocument2d_kssetobjparam.html).

2\. Используется для всех видов, в том числе и для обычного (неассоциативного) вида.

Подразделы:

(отсутствуют)
