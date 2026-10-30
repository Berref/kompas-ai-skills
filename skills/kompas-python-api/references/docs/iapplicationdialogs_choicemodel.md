# ChoiceModel - Диалог "Выбрать модель" из списка открытых

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IApplicationDialogs ](iapplicationdialogs.html) > [IApplicationDialogs - методы ](iapplicationdialogs_methods.html) |  Scroll [ [ [ ](iapplicationdialogs_getdialogparam.html "К следующему разделу")](iapplicationdialogs_methods.html "На уровень выше")](iapplicationdialogs_choicematerial.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplicationdialogs.html)

Синтаксис Automation:

BOOL ChoiceModel( OLE_HANDLE HWnd, IChoiceModelDialogParam * DialogParam );

Синтаксис COM:

HRESULT ChoiceModel( OLE_HANDLE HWnd, IChoiceModelDialogParam * DialogParam, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

HWnd | \- дескриптор окна владельца,  
---|---  
DialogParam | \- параметры диалога выбора материала [IChoiceModelDialogParam](ichoicemodeldialogparam.html).  
  
Версия Компас v23

Подразделы:

(отсутствуют)
