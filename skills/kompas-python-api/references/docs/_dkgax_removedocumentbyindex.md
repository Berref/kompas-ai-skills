# RemoveDocumentByIndex - Закрыть документ с указанным индексом

[KGAX - ActiveX компонент](kgax.html) > [Интерфейсы](co1725258.html) > [Интерфейс _DKGAX ](_dkgax.html) > [Интерфейс _DKGAX - методы ](_dkgax_methods.html) |  Scroll [ [ [ ](_dkgax_activatedocumentbyindex.html "К следующему разделу")](_dkgax_methods.html "На уровень выше")](_dkgax_addnewemptydocument.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](_dkgax.html)

Синтаксис:

VARIANT_BOOL RemoveDocumentByIndex ([in]long index);

Входные параметры:

index | \- индекс документа.  
---|---  
  
Примечание:

1\. Перед закрытием документа должны быть освобождены все интерфейсы, захваченные на данном документе.

2\. После применения метода индексы документов, открытых после данного документа, уменьшаются на 1.

Подразделы:

(отсутствуют)
