# ksSheetSetupDlg - Открыть диалог для задания формата листа

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Общие функции ](common_docum_fncts.html) |  Scroll [ [ [ ](kssheetsetupdlgw.html "К следующему разделу")](common_docum_fncts.html "На уровень выше")](ksdistancecurvecurve.html "К предыдущему разделу")  
---|---  
  
[Пример...](kssheetsetupdlg_example.html)

Синтаксис:

int ksSheetSetupDlg (DocumentParam* docPar, void *HWindow);

Входные параметры:

docPar | [\- указатель на ](structdocumentparam.html)[структуру параметров документа](structdocumentparam.html),  
---|---  
Hwindow | \- дескриптор окна.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- при выходе из диалога по отмене.  
  
Примечание:

1\. Параметры docPar могут быть только параметрами чертежа, для любого другого типа документа функция ничего не сделает. Перед использованием функции необходимо правильно проинициализировать структуру docPar.

2\. При использовании Unicode следует использовать функцию [ksSheetSetupDlgW](kssheetsetupdlgw.html).

Подразделы:

(отсутствуют)
