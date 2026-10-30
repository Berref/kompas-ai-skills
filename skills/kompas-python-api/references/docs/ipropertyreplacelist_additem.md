# AddItem - Добавить найденный фрагмент текста

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyReplaceList ](ipropertyreplacelist.html) > [IPropertyReplaceList - методы ](ipropertyreplacelist_methods.html) |  Scroll [ [ [ ](ipropertyreplacelist_clear.html "К следующему разделу")](ipropertyreplacelist_methods.html "На уровень выше")](ipropertyreplacelist_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyreplacelist.html)

Синтаксис Automation:

BOOL AddItem( LPDISPATCH Document, BSTR Text, BSTR FindText, long StartIndex, BOOL ReadOnly );

Синтаксис COM:

HRESULT AddItem( IDocumentFrame * Document, BSTR Text, BSTR FindText, long StartIndex, BOOL ReadOnly, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Document | \- указатель на интерфейс окна документа [IDocumentFrame](idocumentframe.html),  
---|---  
Text | \- полный текст,  
FindText | \- найденный текст,  
StartIndex | \- позиция найденного текста в полном тексте,  
ReadOnly | \- признак недоступного для изменения документа.  
  
Подразделы:

(отсутствуют)
