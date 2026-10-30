# SetTexts - Установить тексты и их параметры

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [OpenGL ](ba1848735.html) > [Интерфейс IExternalGDIObject ](iexternalgdiobject.html) > [IExternalGDIObject - методы ](iexternalgdiobject_methods.html) |  Scroll [ [ [ ](iexternalgdiobject_settextsalign.html "К следующему разделу")](iexternalgdiobject_methods.html "На уровень выше")](iexternalgdiobject_settextorientation.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iexternalgdiobject.html)

Синтаксис Automation:

BOOL SetTexts( VARIANT Texts,

VARIANT Points,

VARIANT Colors,

VARIANT Fonts,

BOOL Is3DPoints );

Синтаксис COM:

HRESULT SetTexts( VARIANT Texts,

VARIANT Points,

VARIANT Colors,

VARIANT Fonts,

BOOL Is3DPoints,

BOOL * Result );

Входные параметры:

Points | \- массив SafeArray VT_ARRAY | VT_R8 координат точек отрисовки текстов. Координаты в массиве могут лежать в последовательности: \- для Is3DPoints == TRUE x0, y0, z0, x1, y1, z1, ... xi, yi, zi \- для Is3DPoints == FALSE x0, y0, x1, y1, ... xi, yi,  
---|---  
Texts | \- массив SafeArray VT_ARRAY | VT_BSTR текстов,  
Сolors | \- массив цветов текстов. Массив может быть не задан - тип VARIANT-а VT_EMPTY, в этом случае используется черный цвет. Может быть задан один цвет - тип VARIANT-а VT_I4. Может быть задан цвет для каждого текста тип VARIANT-а VT_ARRAY | VT_I4,  
Fonts | \- массив шрифтов текстов. Массив может быть не задан - тип VARIANT-а VT_EMPTY. В этом случае используется шрифт, установленный в модели. Может быть задан один шрифт - тип VARIANT-а VT_DISPATCH. Может быть задан шрифт для каждого текста тип VARIANT-а VT_ARRAY | VT_DISPATCH. Передаваемый интерфейс - интерфейс IFontDispPtr, который можно получить от объекта MFC- класса CFontHolder,  
Is3DPoints | \- признак использования 3D-координат отрисовки текстов.  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
