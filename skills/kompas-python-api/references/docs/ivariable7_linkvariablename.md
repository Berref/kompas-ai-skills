# LinkVariableName - Имя переменной, на которую сделана ссылка

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Переменные ](ba1859837.html) > [Интерфейс IVariable7 ](ivariable7.html) > [IVariable7 - свойства ](ivariable7_props.html) |  Scroll [ [ [ ](ivariable7_lowdeviation.html "К следующему разделу")](ivariable7_props.html "На уровень выше")](ivariable7_linkembodimentindex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ivariable7.html)

Тип данных: BSTR

Синтаксис Automation:

LinkVariableName = Object.LinkVariableName | Получить свойство ([* ](1.html))  
---|---  
LinkVariableName = Object.GetLinkVariableName() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_LinkVariableName( &LinkVariableName ) | Получить свойство  
---|---  
  
Свойство позволяет получить имя переменной, на которую сделана ссылка.

Примечание:

Свойство доступно только для чтения.

Переменная может ссылаться на переменную из другого документа.

Ссылка формируется из имени документа [IVariable7::LinkDocumentName](ivariable7_linkdocumentname.html) и имени переменной.

Ссылку можно создать с помощью функции [IVariable7::SetLink](ivariable7_setlink.html).

Подразделы:

(отсутствуют)
