# Save - Сохранить задание на печать в файл

[API интерфейсов. Версия 7](applicate.html) > [Печать ](bh1473974.html) > [Интерфейс IPrintJob ](iprintjob.html) > [IPrintJob - методы ](iprintjob_methods.html) |  Scroll [ [ [ ](iprintjob_showpreviewwindow.html "К следующему разделу")](iprintjob_methods.html "На уровень выше")](iprintjob_removesheets.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprintjob.html)

Синтаксис Automation:

BOOL Save( BSTR FileName,

VARIANT * Errors );

Синтаксис COM:

HRESULT Save( BSTR FileName,

VARIANT * Errors,

BOOL * Result );

Входные параметры:

FileName | \- имя файла задания на печать.  
---|---  
  
Выходные параметры:

Errors | \- массив VT_ARRAY | VT_BSTR, если есть ошибки.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет сохранить задание на печать в файл *.pjd.

Подразделы:

(отсутствуют)
