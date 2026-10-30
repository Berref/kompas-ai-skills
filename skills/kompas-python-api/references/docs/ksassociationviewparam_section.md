# section - Признак разрез/сечение

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров формата и компоновки чертежа ](ce1717197.html) > [Интерфейс параметров ассоциативного вида (Интерфейс ksAssociationViewParam) ](ksassociationviewparam.html) > [ksAssociationViewParam - свойства ](ksassociationviewparam_props.html) |  Scroll [ [ [ ](ksassociationviewparam_tangentedgesshow.html "К следующему разделу")](ksassociationviewparam_props.html "На уровень выше")](ksassociationviewparam_samehatch.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksassociationviewparam.html)

Тип данных:BOOL.

Значения свойства:

TRUE | \- сечение,  
---|---  
FALSE | \- разрез.  
  
Синтаксис Automation:

section = iAssViewParam.section | Получить свойство ([* ](1.html))  
---|---  
iAssViewParam.section = section | Установить свойство ([* ](1.html))  
section = iAssViewParam.GetSection() | Получить свойство ([**](2.html))  
iAssViewParam.SetSection(section) | Установить свойство ([**](2.html))  
  
Примечание:

Свойство используется только для видов типа разрез или сечение.

Подразделы:

(отсутствуют)
