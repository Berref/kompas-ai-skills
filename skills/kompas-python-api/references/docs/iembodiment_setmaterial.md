# SetMaterial - Установить материал

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IEmbodiment ](iembodiment.html) > [IEmbodiment - методы ](iembodiment_methods.html) |  Scroll [ [ [ ](iembodiment_update.html "К следующему разделу")](iembodiment_methods.html "На уровень выше")](iembodiment_setmarking.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iembodiment.html)

Синтаксис Automation:

BOOL SetMaterial( BSTR Name, double Density );

Синтаксис COM:

HRESULT SetMaterial( BSTR Name, double Density, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Name | \- наименование материала,  
---|---  
Density | \- плотность материала.  
  
Подразделы:

(отсутствуют)
