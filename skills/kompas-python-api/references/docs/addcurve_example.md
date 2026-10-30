# IImportedSurfaceDefinition::AddCurve - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void WorkImportedSurfaceAddCurve( KompasObject &kompas ){

int pointCountAll = 6; //кратное трем (x, y, z)

int curveCount = 3;

double x = 50, dx = 30;

double y = 50, dy = 40;

double z = 0, dz = 100;

int pointCount = pointCountAll / 3;

SAFEARRAYBOUND sabound[1];

SAFEARRAY FAR *psa;

// Создание safe array double

sabound[0].cElements = pointCountAll;

sabound[0].lLbound = 0;

psa =::SafeArrayCreate(VT_R8, 1, sabound);

VARIANT v;

VariantInit(&v);

V_VT(&v) = VT_ARRAY | VT_R8;

V_ARRAY(&v) = psa;

long index;

double d;

if ( kompas.m_lpDispatch ) {

//получить активный 3d документ

ksDocument3D doc( kompas.ActiveDocument3D() );

if ( doc.m_lpDispatch ) {

//получить компонент документа

ksPart part( doc.GetPart( pTop_Part) );

if ( part ) {

//получить новый объект импортированной поверхности

ksEntity entity(part.NewEntity(o3d_importedSurface);

if (entity) {

//Определение импортированной поверхности

ksImportedSurfaceDefinition importedSurfaceDef( entity.GetDefinition());

//добавляем в импортированную поверхность кривые по массиву точек

if (importedSurfaceDef){

for ( uint i = 0; i < curveCount; i ) {

for (uint j = 0; j < pointCount; j ) {

//наполняем safe array. Каждая точка представлена тремя координатами x, y, z

index = j*3;

d = x dx*i;

::SafeArrayPutElement(psa, &index, &d);

index = j*3 1;

d = y - dy*(i%2);

::SafeArrayPutElement(psa, &index, &d);

index = j*3 2;

d = z dz*j;

::SafeArrayPutElement(psa, &index, &d);

}

//добавить кривую по массиву точек

importedSurfaceDef.AddCurve ( v );

}

//создать импортированную поверхность

entity.Create();

}

}

}

}

else

kompas.ksError( "3d документ не активизирован" );

}

//удалить safe array double

if ( psa )

::SafeArrayDestroy(psa);

}
