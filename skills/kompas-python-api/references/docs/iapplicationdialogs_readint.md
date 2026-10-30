# ReadInt - Ввод целого числа

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IApplicationDialogs ](iapplicationdialogs.html) > [IApplicationDialogs - методы ](iapplicationdialogs_methods.html) |  Scroll [ [ [ ](iapplicationdialogs_readstring.html "К следующему разделу")](iapplicationdialogs_methods.html "На уровень выше")](iapplicationdialogs_readdouble.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplicationdialogs.html)

Синтаксис Automation:

BOOL ReadInt( OLE_HANDLE HWnd, BSTR Caption, long Value, long MinValue, long MaxValue, long * NewValue );

Синтаксис COM:

HRESULT ReadInt( OLE_HANDLE HWnd, BSTR Caption, long Value, long MinValue, long MaxValue, long * NewValue, BOOL * Result );

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
