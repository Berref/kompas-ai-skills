# ChoiceMaterial - Выбрать материал из системного файла graphic.dsn

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IApplicationDialogs ](iapplicationdialogs.html) > [IApplicationDialogs - методы ](iapplicationdialogs_methods.html) |  Scroll [ [ [ ](iapplicationdialogs_choicemodel.html "К следующему разделу")](iapplicationdialogs_methods.html "На уровень выше")](iapplicationdialogs_choicefiles.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplicationdialogs.html)

Синтаксис Automation:

BOOL ChoiceMaterial( OLE_HANDLE HWnd, IChoiceMaterialDialogParam * MaterialParam );

Синтаксис COM:

HRESULT ChoiceMaterial( OLE_HANDLE HWnd, IChoiceMaterialDialogParam * MaterialParam, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

HWnd | \- дескриптор окна владельца,  
---|---  
MaterialParam | \- параметры диалога выбора материала [IChoiceMaterialDialogParam](ichoicematerialdialogparam.html).  
  
Версия Компас v23

Подразделы:

(отсутствуют)
