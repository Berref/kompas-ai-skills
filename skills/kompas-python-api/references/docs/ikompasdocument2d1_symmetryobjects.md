# SymmetryObjects - Симметрия объектов относительно оси

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - методы ](ikompasdocument2d1_methods.html) |  Scroll [ [ [ ](ikompasdocument2d1_transformangleintomatrix.html "К следующему разделу")](ikompasdocument2d1_methods.html "На уровень выше")](ikompasdocument2d1_selectobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Синтаксис Automation:

LPDISPATCH SymmetryObjects( VARIANT Objects, double X1, double Y1, double X2, double Y2, BOOL Copy, BOOL TextSymmetry, BOOL CopyAttribytes );

Синтаксис COM:

HRESULT SymmetryObjects( VARIANT Objects, double X1, double Y1, double X2, double Y2, BOOL Copy, BOOL TextSymmetry, BOOL CopyAttribytes, IKompasAPIObject * * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Objects | \- объект (VT_DISPATCH) или список объектов (VT_ARRAY | VT_DISPATCH),  
---|---  
X1, Y1 | \- координаты первой точки на оси,  
X2, Y2 | \- координаты второй точки на оси,  
Copy | \- режим копирования: •FALSE - исходные объекты удаляются, •TRUE - исходные объекты оставляются,  
TextSymmetry | \- зеркалировать тексты,  
CopyAttribytes | \- копировать атрибуты.  
  
Версия Компас v23

Подразделы:

(отсутствуют)
