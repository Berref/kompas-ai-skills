# LinkType - Режим связки сборки или чертежа со спецификацией

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuning ](ispecificationtuning.html) > [ISpecificationTuning - свойства ](ispecificationtuning_props.html) |  Scroll [ [ [ ](ispecificationtuning_nestingblocktextstylefirst.html "К следующему разделу")](ispecificationtuning_props.html "На уровень выше")](ispecificationtuning_insertnull.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuning.html)

Тип данных: из перечисления [ksSpecificationLinkTypeEnum](ksspecificationlinktypeenum.html)

Синтаксис Automation:

LinkType = iObject.LinkType | Получить свойство ([* ](1.html))  
---|---  
iObject.LinkType = LinkType | Установить свойство ([* ](1.html))  
LinkType = iObject.GetLinkType() | Получить свойство ([**](2.html))  
iObject.SetLinkType (LinkType) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_LinkType (&LinkType) | Получить свойство  
---|---  
iObject->put_LinkType (LinkType) | Установить свойство  
  
Значения свойства:

slNone | \- информация из подключенного сборочного чертежа не будет передаваться в спецификацию, однако чертеж будет по-прежнему подключен, и связь можно будет включить в любой момент,  
---|---  
slOnlyObjects | \- при сохранении подключенного чертежа, в который внесены изменения, касающиеся спецификации (созданы или отредактированы объекты спецификации), эти изменения будут переданы в спецификацию.  
slWithPositionCalculate | \- после передачи изменений из чертежа в спецификацию в ней будет автоматически произведен расчет номеров позиций (в соответствии с последовательностью сортировки объектов), и новые номера позиций будут переданы в чертеж.  
  
Примечание:

Позволяет включать и блокировать связь, подключенных друг к другу документов - спецификации и модели (сборочного чертежа), и устанавливать тип этой связи.

Подразделы:

(отсутствуют)
