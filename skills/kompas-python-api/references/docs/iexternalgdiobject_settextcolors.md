# SetTextColors - Установить цвета текстов

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [OpenGL ](ba1848735.html) > [Интерфейс IExternalGDIObject ](iexternalgdiobject.html) > [IExternalGDIObject - методы ](iexternalgdiobject_methods.html) |  Scroll [ [ [ ](iexternalgdiobject_settextorientation.html "К следующему разделу")](iexternalgdiobject_methods.html "На уровень выше")](iexternalgdiobject_setplace.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iexternalgdiobject.html)

Синтаксис Automation:

BOOL SetTextColors( VARIANT textColors );

Синтаксис COM:

HRESULT SetTextColors( VARIANT textColors, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

textColors | \- массив цветов - SafeArray целых чисел VT_ARRAY | VT_I4.  
---|---  
  
Подразделы:

(отсутствуют)
