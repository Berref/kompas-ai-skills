# DrawToDC - Отрисовать документ на заданном HDC

[KGAX - ActiveX компонент](kgax.html) > [Интерфейсы](co1725258.html) > [Интерфейс _DKGAX ](_dkgax.html) > [Интерфейс _DKGAX - методы ](_dkgax_methods.html) |  Scroll [ [ [ ](_dkgax_zoomwindow.html "К следующему разделу")](_dkgax_methods.html "На уровень выше")](_dkgax_invalidateactivedocument.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](_dkgax.html)

Синтаксис:

VARIANT_BOOL DrawToDC ([in]OLE_HANDLE dc, [in]long left, [in]long top, [in]long width, [in]long height);

Входные параметры:

dc | \- OLE_HANDLE на котором необходимо отрисовать документ, например HDC принтера или окна,  
---|---  
left, top, width, height | \- задают квадрат участка документа.  
  
Подразделы:

(отсутствуют)
