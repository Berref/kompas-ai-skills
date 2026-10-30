# RemoveContourGaps - Устранить разрывы в контуре

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IContour ](icontour.html) > [IContour - методы ](icontour_methods.html) |  Scroll [ [ [ ](icontoursegment.html "К следующему разделу")](icontour_methods.html "На уровень выше")](icontour_copysegments.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icontour.html)

Синтаксис Automation:

BOOL RemoveContourGaps( double Accuracy, BOOL CanInsert, BOOL CanReplace );

Синтаксис COM:

HRESULT RemoveContourGaps( double Accuracy, BOOL CanInsert, BOOL CanReplace, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Входные параметры:

Accuracy | \- размер разрывов,  
---|---  
CanInsert | \- разрешение на вставку сегментов,  
CanReplace | \- разрешение на подмену сегментов.  
  
Подразделы:

(отсутствуют)
