# Close - Закрыть документ

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument ](ikompasdocument.html) > [IKompasDocument - методы ](ikompasdocument_methods.html) |  Scroll [ [ [ ](ikompasdocument_save.html "К следующему разделу")](ikompasdocument_methods.html "На уровень выше")](ikompasdocument_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument.html)

Синтаксис Automation:

BOOL Close (DocumentCloseOptions closeOptions);

Синтаксис COM:

HRESULT Close ([in, defaultvalue(FALSE)] DocumentCloseOptions closeOptions, [out, retval] VARIANT_BOOL* pRes);

Входные параметры:

closeOptions | \- действия при закрытии измененного документа из перечисления [DocumentCloseOptions](documentcloseoptions.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Если документ не был изменен или его уже сохранили перед закрытием, то значение входного параметра будет проигнорировано.

2\. Если документ был изменен, то возможны три варианта:

•закрыть документ без сохранения – kdDoNotSaveChanges (в этом случае все изменения будут потеряны),

•закрыть документ с сохранением – kdSaveChanges (в этом случае документ будет сначала сохранен, а потом закрыт),

•предоставить право выбора пользователю – kdPromptToSaveChanges (в этом случае на экран будет выведено сообщение о возможных действиях). Если закрываем в режиме kdPromptToSaveChanges, то пользователь может вообще отказаться от закрытия измененного документа, в этом случае метод вернет FALSE.

Подразделы:

(отсутствуют)
