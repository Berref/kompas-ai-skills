# ReadDouble - Ввод вещественного числа

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IApplicationDialogs ](iapplicationdialogs.html) > [IApplicationDialogs - методы ](iapplicationdialogs_methods.html) |  Scroll [ [ [ ](iapplicationdialogs_readint.html "К следующему разделу")](iapplicationdialogs_methods.html "На уровень выше")](iapplicationdialogs_getdialogparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplicationdialogs.html)

Синтаксис Automation:

BOOL ReadDouble( OLE_HANDLE HWnd, BSTR Caption, double Value, double MinValue, double MaxValue, double * NewValue );

Синтаксис COM:

HRESULT ReadDouble( OLE_HANDLE HWnd, BSTR Caption, double Value, double MinValue, double MaxValue, double * NewValue, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

HWnd | \- дескриптор окна владельца,  
---|---  
Caption | \- заголовок,  
Value | \- текущее значение,  
MinValue | \- минимальное значение,  
MaxValue | \- максимальное значение.  
  
Выходные параметры:

NewValue | \- новое значение.  
---|---  
  
Версия Компас v23

Подразделы:

(отсутствуют)
