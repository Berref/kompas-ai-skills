# GetLinkEmbodimentMarking - Обозначение исполнения

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Переменные ](ba1859837.html) > [Интерфейс IVariable7 ](ivariable7.html) > [IVariable7 - методы ](ivariable7_methods.html) |  Scroll [ [ [ ](ivariable7_setlink.html "К следующему разделу")](ivariable7_methods.html "На уровень выше")](ivariable7_delete.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ivariable7.html)

Синтаксис Automation:

BSTR GetLinkEmbodimentMarking( ksVariantMarkingTypeEnum MarkingType, BOOL AddSystemDelimer );

Синтаксис COM:

HRESULT GetLinkEmbodimentMarking( ksVariantMarkingTypeEnum MarkingType, BOOL AddSystemDelimer, BSTR * Result );

Возвращаемое значение:

TRUE | \- в случае удачи,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

MarkingType | \- часть обозначения из перечисления [ksVariantMarkingTypeEnum](ksvariantmarkingtypeenum.html),  
---|---  
AddSystemDelimer | \- добавлять системные разделители.  
  
Подразделы:

(отсутствуют)
