# SaveDocumentExW - Сохранить документ в выбранной версии (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Общие функции ](common_docum_fncts.html) |  Scroll [ [ [ ](getdocoptions.html "К следующему разделу")](common_docum_fncts.html "На уровень выше")](savedocumentex.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksSaveDocumentEx](ksdocument2d_kssavedocumentex.html).

Синтаксис:

int LIB_FUNC SaveDocumentExW (reference doc, LPWSTR fileName, int version);

Входные параметры:

doc | \- указатель на документ,  
---|---  
fileName | \- полное имя файла,  
version | \- версия для сохранения: -1 - в предыдущую версию, 0 - в текущую версию, 1 - в версию 5.11.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Если doc = 0, метод сохраняет текущий документ.

2\. Если fileName = NULL, то используется имя файла из документа. Если же и в документе отсутствует имя файла, то взводится ошибка.

3\. При использовании ANSI следует использовать функцию [SaveDocumentEx](savedocumentex.html).

Подразделы:

(отсутствуют)
