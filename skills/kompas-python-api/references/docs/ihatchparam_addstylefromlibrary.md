# AddStyleFromLibrary - Инициализация стиля штриховки из библиотеки стилей

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Параметры ](bb2370796.html) > [Интерфейс IHatchParam ](ihatchparam.html) > [IHatchParam - методы ](ihatchparam_methods.html) |  Scroll [ [ [ ](iphantom2d.html "К следующему разделу")](ihatchparam_methods.html "На уровень выше")](ihatchparam_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ihatchparam.html)

Синтаксис Automation:

BOOL AddStyleFromLibrary( BSTR FileName, double StyleNumber);

Синтаксис COM:

HRESULT AddStyleFromLibrary( BSTR FileName, double StyleNumber, BOOL * Result );

Входные параметры:

FileName | \- имя файла для стиля штриховки,  
---|---  
StyleNumber | \- идентификатор стиля в библиотеке.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
