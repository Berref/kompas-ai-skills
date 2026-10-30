# ShowContentDialog - Диалог с произвольным наполнением

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IApplicationDialogs ](iapplicationdialogs.html) > [IApplicationDialogs - методы ](iapplicationdialogs_methods.html) |  Scroll [ [ [ ](iapplicationdialogs_whatswrongdlg.html "К следующему разделу")](iapplicationdialogs_methods.html "На уровень выше")](iapplicationdialogs_selectthread.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplicationdialogs.html)

Синтаксис Automation:

long ShowContentDialog( OLE_HANDLE ParentHwnd, IContentDialogParam * DialogParam );

Синтаксис COM:

HRESULT ShowContentDialog( OLE_HANDLE ParentHwnd, IContentDialogParam * DialogParam, long * Result );

Возвращаемое значение:

| \- результат работы диалога.  
---|---  
  
Входные параметры:

TParentHwnd | \- дескриптор родительского окна,  
---|---  
DialogParam | \- параметры диалога [IContentDialogParam](icontentdialogparam.html).  
  
Подразделы:

(отсутствуют)
