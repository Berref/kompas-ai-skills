# SelectThread - Выбор стандарта резьбы

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IApplicationDialogs ](iapplicationdialogs.html) > [IApplicationDialogs - методы ](iapplicationdialogs_methods.html) |  Scroll [ [ [ ](iapplicationdialogs_showcontentdialog.html "К следующему разделу")](iapplicationdialogs_methods.html "На уровень выше")](iapplicationdialogs_savefile.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplicationdialogs.html)

Синтаксис Automation:

BOOL SelectThread( OLE_HANDLE ParentHwnd, IThreadDialogParam * DialogParam );

Синтаксис COM:

HRESULT SelectThread( OLE_HANDLE ParentHwnd, IThreadDialogParam * DialogParam, BOOL * Result );

Возвращаемое значение:

TRUE | \- если пользователь закрывает диалог с выбором значения,  
---|---  
FALSE | \- при отмене или ошибке.  
  
Входные параметры:

TParentHwnd | \- дескриптор родительского окна,  
---|---  
DialogParam | \- параметры диалога.  
  
Подразделы:

(отсутствуют)
