# SetTextsAlign - Установить выравнивание текста

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [OpenGL ](ba1848735.html) > [Интерфейс IExternalGDIObject ](iexternalgdiobject.html) > [IExternalGDIObject - методы ](iexternalgdiobject_methods.html) |  Scroll [ [ [ ](iexternaltessellationmanager.html "К следующему разделу")](iexternalgdiobject_methods.html "На уровень выше")](iexternalgdiobject_settexts.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iexternalgdiobject.html)

Синтаксис Automation:

BOOL SetTextsAlign( VARIANT TextsAlign );

Синтаксис COM:

HRESULT SetTextsAlign( VARIANT TextsAlign, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае ошибки.  
  
Входные параметры:

TextsAlign | \- массив SafeArray VT_ARRAY | VT_I4 констант из перечисления [ksTextAlignEnum](kstextalignenum.html).  
---|---  
  
Подразделы:

(отсутствуют)
