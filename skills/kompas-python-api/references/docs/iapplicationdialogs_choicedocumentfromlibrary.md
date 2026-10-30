# ChoiceDocumentFromLibrary - Выбрать документ в библиотеке документов

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IApplicationDialogs ](iapplicationdialogs.html) > [IApplicationDialogs - методы ](iapplicationdialogs_methods.html) |  Scroll [ [ [ ](iapplicationdialogs_choicefile.html "К следующему разделу")](iapplicationdialogs_methods.html "На уровень выше")](iapplicationdialogs_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplicationdialogs.html)

Синтаксис Automation:

BSTR ChoiceDocumentFromLibrary( OLE_HANDLE HWnd, BSTR Title, BSTR LibraryPath, BSTR CurrentDocument, ksDocumentsLibraryInsertionTypeEnum FilterInsertType, ksChoiceFromLibraryResultEnum * ChoiceResult );

Синтаксис COM:

HRESULT ChoiceDocumentFromLibrary( OLE_HANDLE HWnd, BSTR Title, BSTR LibraryPath, BSTR CurrentDocument, ksDocumentsLibraryInsertionTypeEnum FilterInsertType, ksChoiceFromLibraryResultEnum * ChoiceResult, BSTR * Result );

Возвращаемое значение:

| \- Путь к выбранному фрагменту.  
---|---  
  
Входные параметры:

HWnd | \- дескриптор окна владельца,  
---|---  
Title | \- заголовок,  
LibraryPath | \- путь к библиотеке,  
CurrentDocument | \- текущий документ в библиотеке,  
FilterInsertType | \- фильтр типов документов в библиотеке из перечисления  [ksDocumentsLibraryInsertionTypeEnum](ksdocumentslibraryinsertiontypeenum.html).  
  
Выходные параметры:

ChoiceResult | \- результат выбора из перечисления [ksChoiceFromLibraryResultEnum](kschoicefromlibraryresultenum.html).  
---|---  
  
Версия Компас v23

Подразделы:

(отсутствуют)
