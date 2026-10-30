# GetGabaritModifying - Изменился ли габарит документа

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [OpenGL ](ba1848735.html) > [Интерфейс IGabaritObject ](igabaritobject.html) > [IGabaritObject - методы ](igabaritobject_methods.html) |  Scroll [ [ [ ](ksglobject.html "К следующему разделу")](igabaritobject_methods.html "На уровень выше")](igabaritobject_getcurrentgabarit.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](igabaritobject.html)

Синтаксис Automation:

BOOL GetGabaritModifying();

Синтаксис COM:

HRESULT GetGabaritModifying ([out, retval]VARIANT_BOOL * DocGabaritModify);

Возвращаемое значение:

TRUE | \- габарит документа изменен,  
---|---  
FALSE | \- габарит документа не изменен.  
  
Примечание:

В момент отработки события Определение габаритов документа метод позволяет узнать менялся ли габарит документа или нет.

Подразделы:

(отсутствуют)
