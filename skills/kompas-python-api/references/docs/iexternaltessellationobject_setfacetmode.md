# SetFacetMode - Установить режим отображения граней

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [OpenGL ](ba1848735.html) > [Интерфейс IExternalTessellationObject ](iexternaltessellationobject.html) > [IExternalTessellationObject - методы ](iexternaltessellationobject_methods.html) |  Scroll [ [ [ ](iexternaltessellationobject_setplaces.html "К следующему разделу")](iexternaltessellationobject_methods.html "На уровень выше")](iexternaltessellationobject_setedgewidths.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iexternaltessellationobject.html)

Синтаксис Automation:

BOOL SetFacetMode( BOOL SideMode,

ksFacetCullingMode CullingMode );

Синтаксис COM:

HRESULT SetFacetMode( BOOL SideMode,

ksFacetCullingMode CullingMode, BOOL * Res );

Входные параметры:

SideMode | \- TRUE - объект является двусторонним, \- FALSE - объект является односторонним,  
---|---  
CullingMode | \- режим отображения граней [ksFacetCullingMode](ksfacetcullingmode.html).  
  
Возвращаемое значение:

TRUE | \- в случае удачи.  
---|---  
  
Подразделы:

(отсутствуют)
