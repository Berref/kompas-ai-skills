# Интерфейс GLObject - методы

[KGAX - ActiveX компонент](kgax.html) > [Интерфейсы](co1725258.html) > [Интерфейс GLObject ](globject.html) |  Scroll [ [ [ ](co1726548.html "К следующему разделу")](globject.html "На уровень выше")](globject.html "К предыдущему разделу")  
---|---  
  
VARIANT_BOOL glBegin ([in]long mode);

VARIANT_BOOL glEnd();

VARIANT_BOOL glEnable ([in]long cap);

VARIANT_BOOL glDisable ([in]long cap);

VARIANT_BOOL glColor3d ([in]double r, [in]double g, [in]double b);

VARIANT_BOOL glLineWidth ([in]double w);

VARIANT_BOOL glLineStipple ([in]long factor, [in]short pattern);

VARIANT_BOOL glPointSize ([in]double w);

VARIANT_BOOL glPolygonMode ([in]long face, [in]long mode);

VARIANT_BOOL glVertex2d ([in]double x, [in]double y);

VARIANT_BOOL glVertex2dv ([in]double* pData, [in]long countDouble);

VARIANT_BOOL glVertex3d ([in]double x, [in]double y, [in]double z);

VARIANT_BOOL glVertex3dv ([in]double* pData, [in]long countDouble);

VARIANT_BOOL glVertex4d ([in]double x, [in]double y, [in]double z, [in]double w);

VARIANT_BOOL glVertex4dv ([in]double* pData, [in]long countDouble);

Подразделы:

(отсутствуют)
