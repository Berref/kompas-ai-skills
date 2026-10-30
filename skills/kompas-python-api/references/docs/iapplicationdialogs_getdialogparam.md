# GetDialogParam - Получить интерфейс параметров для вызова диалога

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IApplicationDialogs ](iapplicationdialogs.html) > [IApplicationDialogs - методы ](iapplicationdialogs_methods.html) |  Scroll [ [ [ ](iapplicationdialogs_readdouble.html "К следующему разделу")](iapplicationdialogs_methods.html "На уровень выше")](iapplicationdialogs_choicemodel.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplicationdialogs.html)

Синтаксис Automation:

LPDISPATCH GetDialogParam( KompasAPIObjectTypeEnum ParamType );

Синтаксис COM:

HRESULT GetDialogParam( KompasAPIObjectTypeEnum ParamType, IKompasAPIObject * * Result );

Возвращаемое значение:

| \- интерфейс параметров диалога в зависимости от параметра ParamType.  
---|---  
  
Входные параметры:

ParamType | \- тип параметров диалога.  
---|---  
ksObjectThreadDialogParam | \- параметры диалога Выбор стандарта резьбы [IThreadDialogParam](ithreaddialogparam.html) для функции [IApplicationDialogs::SelectThread](iapplicationdialogs_selectthread.html).  
  
Подразделы:

(отсутствуют)
