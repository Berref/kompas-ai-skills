////////////////////////////////////////////////////////////////////////////////
//
// Обработка событий окна документа
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

#include <GL\gl.h>
#include <GL\GLU.h>
#include "cFrameEvent.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
//#pragma comment(lib, "glaux.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern AFX_MODULE_STATE * pModuleState;

//extern cBaseEvent* NewDocumentEvent( reference doc );

int DocumentFrameEvent::redrawType = 0;

//-------------------------------------------------------------------------------
// Создание подписки на событие окна документа
// ---
cBaseEvent * NewDocumentFrameEvent( IDocumentFrame * documentFrame, reference doc, int redrawType = 0 ) 
{
  cBaseEvent * res = NULL;
  if ( doc && documentFrame ) {
    if ( !cBaseEvent::FindEvents( ntDocumentFrameNotify, doc, -1, documentFrame ) ) {
//      NewDocumentEvent( doc );
      res = new DocumentFrameEvent( documentFrame, doc );
      if ( !res->Advise() ) {
        delete res;
        res = NULL;
      }
    }
    DocumentFrameEvent::redrawType = redrawType;
  }
  return res;
}

//-------------------------------------------------------------------------------
// Разукрасим грани
// ---
void RedrawFace( IPart * topPart, IPart * nextPart, IFaceDefinition * fDef0 )
{
  bool transform = topPart && topPart != nextPart;
  if ( fDef0 ) 
  {
    // Получаем треангуляцию 
    ITessellationPtr tess( fDef0->GetTessellation(), false );
    if ( tess ) 
    {
      _variant_t poins;
      _variant_t indexes;
      _variant_t normals;
      // Новый метод получения параметров триангуляции
      tess->GetFacetPoints( &poins, &indexes );
      tess->GetFacetNormals( &normals );
      if ( indexes.vt == (VT_ARRAY | VT_I4) && indexes.parray &&
           poins.vt   == (VT_ARRAY | VT_R8) && poins.parray   && 
           normals.vt == (VT_ARRAY | VT_R8) && normals.parray ) 
      {
        // массив должен быть одномерный и количество точек должно быть кратно трем
        int count = indexes.parray->rgsabound[0].cElements - indexes.parray->rgsabound[0].lLbound;
        int HUGEP * pIndexes = NULL; // Указатель на массив индексов 
    
        if ( indexes.parray->cDims == 1 && count && !(count % 3) ) 
        {
          ::SafeArrayAccessData( indexes.parray, (void HUGEP* FAR*)&pIndexes );
        }

        int count1 = poins.parray->rgsabound[0].cElements - poins.parray->rgsabound[0].lLbound;
        double HUGEP * pPoints = NULL; // Указатель на массив точек
        if ( poins.parray->cDims == 1 && count1 && !(count1 % 3) ) 
        {
          ::SafeArrayAccessData( poins.parray, (void HUGEP* FAR*)&pPoints );
        }
    
        int count2 = normals.parray->rgsabound[0].cElements - normals.parray->rgsabound[0].lLbound;
        double HUGEP * pNormals = NULL; // Указатель на массив точек
        if ( normals.parray->cDims == 1 && count1 && !(count1 % 3) ) 
        {
          ::SafeArrayAccessData( normals.parray, (void HUGEP* FAR*)&pNormals );
        }

        if ( pIndexes && pPoints && pNormals )
        {
          int trianglesCount = count / 3;

          for ( int i = 0, j = 0; i < trianglesCount; i++, j++ ) 
          {
            glBegin( GL_TRIANGLES );
              double x, y, z;
              int index = pIndexes[j] * 3; // Индекс первой вершины
              // Получение координат вершин треугольника
                x = pPoints[index++];      // Координаты первой вершины
                y = pPoints[index++];
                z = pPoints[index];
                if ( transform )
                  // Перевод координат из системы координат детали в систему координат сборки
                  topPart->TransformPoint( &x, &y, &z, nextPart ); 
                glColor3d( 1.0f, 0.0f, 0.0f );
                glVertex3d( x, y, z );
              index = pIndexes[j++] * 3;   // Индекс нормали первой вершины
                x = pNormals[index++];     // Координаты нормали первой вершины
                y = pNormals[index++];
                z = pNormals[index];
                glNormal3d( x, y, z );
              
              index = pIndexes[j] * 3;     // Индекс второй вершины
                x = pPoints[index++];      // Координаты второй вершины
                y = pPoints[index++];
                z = pPoints[index];
                if ( transform )
                  // Перевод координат из системы координат детали в систему координат сборки
                  topPart->TransformPoint( &x, &y, &z, nextPart );
                glColor3d( 0.0f, 1.0f, 0 );
                glVertex3d( x, y, z );
              index = pIndexes[j++] * 3;   // Индекс нормали второй вершины
                x = pNormals[index++];     // Координаты нормали второй вершины
                y = pNormals[index++];
                z = pNormals[index];
                glNormal3d( x, y, z );
        
              index = pIndexes[j] * 3;     // Индекс третьей вершины
                x = pPoints[index++];      // Координаты третьей вершины
                y = pPoints[index++];
                z = pPoints[index];
                if ( transform )
                  // Перевод координат из системы координат детали в систему координат сборки
                  topPart->TransformPoint( &x, &y, &z, nextPart );
                glColor3d( 0.0f, 0.0f, 1.0f );
                glVertex3d( x, y, z );
              index = pIndexes[j] * 3;     // Индекс нормали третьей вершины
                x = pNormals[index++];     // Координаты нормали третьей вершины
                y = pNormals[index++];
                z = pNormals[index];
                glNormal3d( x, y, z );
            glEnd();
          }
        }
        if ( pIndexes )
          ::SafeArrayUnaccessData( indexes.parray ); // Завершение работы с массивом 
        if ( pPoints )
          ::SafeArrayUnaccessData( poins.parray );   // Завершение работы с массивом
        if ( pNormals )
          ::SafeArrayUnaccessData( normals.parray ); // Завершение работы с массивом
      }
    }
  }
}

//-------------------------------------------------------------------------------
// Разукрасим грани
// ---
void RedrawFaces( IPart * topPart, IPart * nextPart, IEntityCollection * faces )
{
  for ( int ie = 0, count = faces ? faces->GetCount() : 0; ie < count; ie++ ) 
  {
    IEntityPtr face0( faces->GetByIndex(ie), false ); // Получаем грань по индексу
    if ( (bool)face0 && face0->IsCreated() )                // Если она создана
    {
      // Получаем параметры грани
      IFaceDefinitionPtr fDef0( IUnknownPtr( face0->GetDefinition(), false ) );
      RedrawFace( topPart, nextPart, fDef0 );
    }
  }
}


//-------------------------------------------------------------------------------
// Разукрасим грани
// ---
void RedrawFaces( IPart * topPart, IPart * nextPart, IFaceCollection * faces )
{
  for ( int ie = 0, count = faces ? faces->GetCount() : 0; ie < count; ie++ ) 
  {
    IFaceDefinitionPtr face( faces->GetByIndex(ie), false ); // Получаем грань по индексу
    if ( (bool)face )                // Если она создана
    {
      RedrawFace( topPart, nextPart, face );
    }
  }
}

//-------------------------------------------------------------------------------
// Получение коллекции граней детали и их перерисовка
// ---
void RedrawModelFaces( IPart * topPart, IPart * nextPart )
{
  if ( nextPart && nextPart->IsDetail() && !nextPart->GetHidden() && !nextPart->GetExcluded() )
  {
    switch ( DocumentFrameEvent::redrawType )
    {
      case 0: // Получаем грани с детали
      {
        IEntityCollectionPtr faces( nextPart->EntityCollection(o3d_face), false );
        RedrawFaces( topPart, nextPart, faces );
        break;
      }  
      case 1: // Получаем грани с операций
      {
        IFeaturePtr partFeature( nextPart->GetFeature(), false ); 
        // Получить коллекцию листов сборки
        IFeatureCollectionPtr featColl( partFeature->SubFeatureCollection(false   // не выдавать скрытые объекты
                                                                       , true), // выдавать библиотечные объекты
                                                                       false ); 
        if ( featColl )
        {
          for ( int i = 0, count = featColl->GetCount(); i < count; i++ )
          {
            IFeaturePtr nextFeature( featColl->GetByIndex(i), false );
            IEntityCollectionPtr faces( nextFeature->EntityCollection(o3d_face), false );
            if ( faces )
              RedrawFaces( topPart, nextPart, faces );
          }
        }
        break;
      }
      case 2: // Получение коллекции граней с коллекции тел
      {
        IBodyCollectionPtr bodyColl( nextPart->BodyCollection(), false );
        if ( bodyColl )
        {
          for ( int i = 0, count = bodyColl->GetCount(); i < count; i++ )
          {
            IBodyPtr body( bodyColl->GetByIndex(i), false/*AddRef*/ );
            if ( body )
            {
              IFaceCollectionPtr faceColl( body->FaceCollection(), false/*AddRef*/ );
              RedrawFaces( topPart, nextPart, faceColl );
            }
          }
        }
        break;
      }
      case 3: // Получение коллекции граней с коллекции тел
      {
        IBodyPtr body( nextPart->GetMainBody(), false );
        if ( body )
        {
          IFaceCollectionPtr faceColl( body->FaceCollection(), false/*AddRef*/ );
          RedrawFaces( topPart, nextPart, faceColl );
        }
        break;
      }
    }
  }
}


void RecursiveDraw( IPart * pTopPart, IFeatureCollection * coll );

//-------------------------------------------------------------------------------
// Рекурсивный обход объектов сборки
// ---
void RecursiveDraw( IPart * pTopPart, IFeature * nextFeature )
{
  if ( pTopPart && nextFeature )
  {
    _bstr_t name( nextFeature->GetName() );
    IUnknownPtr unkObj( nextFeature->GetObject(), false );

    switch ( nextFeature->GetType() )
    {
      case o3d_part:
      {  
        IPartPtr pPart( unkObj );
        if ( (bool)pPart && pPart->IsDetail() )
        {
          RedrawModelFaces( pTopPart, pPart ); // Отрисовка граней модели
        }
        else
        {
          // Получить коллекцию листов сборки
          IFeatureCollectionPtr featColl( nextFeature->SubFeatureCollection(false   // не выдавать скрытые объекты
                                                                           , true), // выдавать состав для макоро-объектов и библиотечных элементов
                                                                           false );  
          RecursiveDraw( pTopPart, featColl ); // Рекурсивный обход по листам сборки
        }
        break;
      }
      case o3d_entity:
      {
        IEntityPtr entity( unkObj );
        if ( entity )
        {
          if ( entity->GetExcluded() || // Исключенный объект
               entity->GetHidden()  )   // Скрытый объект
            break;

          if ( DocumentFrameEvent::redrawType == 1 ) // По граням операций
          {
            // Получение колекций граней для сборочных операций 
            IPartPtr parent( entity->GetParent(), false );
            if ( (bool)parent && !parent->IsDetail() )
            {
              IEntityCollectionPtr coll( nextFeature->EntityCollection(o3d_face), false );
              if ( (bool)coll )
              {
                for ( int i = 0, count = coll->GetCount(); i < count; i++ )
                {
                  // грани сборочной операции могут принадлежать разным деталям
                  IEntityPtr entity( coll->GetByIndex(i), false );
                  if ( entity )
                  {
                    IPartPtr parent( entity->GetParent(), false );
                    if ( parent )
                    {
                      IFaceDefinitionPtr faceDef( IUnknownPtr( entity->GetDefinition(), false ) );
                      RedrawFace( pTopPart, parent, faceDef );
                    }
                  }
                }
                break;
              }
            }
          }
        }

        // Для остальных берем SubFeatureCollection
        IFeatureCollectionPtr featColl( nextFeature->SubFeatureCollection( false, // не выдавать скрытые объекты
                                                                           true   // выдавать состав для макоро-объектов и библиотечных элементов
                                                                           ), false );
        if ( featColl )
        {
          RecursiveDraw( pTopPart, featColl );
          break;
        }
        break;
      }
      case o3d_unknown:
      { 
        // Неопознанный объект берем SubFeatureCollection
        IFeatureCollectionPtr featColl( nextFeature->SubFeatureCollection( false, // не выдавать скрытые объекты
                                                                           true ),
                                                                           false );
        if ( featColl )
        {
          RecursiveDraw( pTopPart, featColl );
        }
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Обход объектов коллекции
// ---
void RecursiveDraw( IPart * pTopPart, IFeatureCollection * coll )
{
  if ( coll )
    for ( int i = 0, count = coll->GetCount(); i < count; i++ )
    {
      IFeaturePtr nextFeature( coll->GetByIndex(i), false );
      if ( !nextFeature->GetExcluded() )
        RecursiveDraw( pTopPart, nextFeature );
    }
}


////////////////////////////////////////////////////////////////////////////////
//
// DocumentEvent  - обработчик событий от документа
//
////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------
//
// ---
DocumentFrameEvent::DocumentFrameEvent(LPUNKNOWN I, reference doc ):
    cBaseEvent(ntDocumentFrameNotify, NULL , 0, I, doc ), down( false )
{
  m_params.pContainer = doc;
}


//-------------------------------------------------------------------------------
//
// ---
DocumentFrameEvent::~DocumentFrameEvent()
{
}

//-----------------------------------------------------------------------------
//
// ---
LPUNKNOWN DocumentFrameEvent::GetUnknown(){
  m_xDocumentFrameNotify.AddRef();
  return &m_xDocumentFrameNotify;
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) DocumentFrameEvent::XDocumentFrameNotify::Release()
{
	METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify)
	return (ULONG)pThis->InternalRelease();
}

//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP_(ULONG) DocumentFrameEvent::XDocumentFrameNotify::AddRef()
{
	METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify)
	return (ULONG)pThis->InternalAddRef();
}


//-----------------------------------------------------------------------------
//
// ---
STDMETHODIMP DocumentFrameEvent::XDocumentFrameNotify::QueryInterface(
	REFIID iid, LPVOID* ppvObj )
{
	METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify)

	ASSERT(AfxIsValidAddress(ppvObj, sizeof(LPVOID), FALSE));

	if ( IsEqualIID(iid, IID_IUnknown) ||
		   IsEqualIID(iid, IID_IDocumentFrameNotify) )
	{
		*ppvObj = this;
		AddRef();
		return S_OK;
	}

	return E_NOINTERFACE;
}

//-----------------------------------------------------------------------------
//Обрабатывается ли библиотекой событие с номером notifyType
// ---
STDMETHODIMP_(VARIANT_BOOL) DocumentFrameEvent::XDocumentFrameNotify::IsNotifyProcess( int notifyType )
{
	return  notifyType >= frBeginPaint && notifyType <= frCloseFrame;
}


//-----------------------------------------------------------------------------
// Начало отрисовки докумета ( в 3D не используется )
// ---
VARIANT_BOOL STDMETHODCALLTYPE DocumentFrameEvent::XDocumentFrameNotify::BeginPaint( IUnknown __RPC_FAR * paintObj ) {
  return true;
}  

double  xMax = 0;


//-----------------------------------------------------------------------------
// Завершение отрисовки докумета ( в 3D не используется )
// ---
VARIANT_BOOL STDMETHODCALLTYPE DocumentFrameEvent::XDocumentFrameNotify::ClosePaint( IUnknown __RPC_FAR * paintObj ) {
  return true;
}


//-----------------------------------------------------------------------------
// Нажатие кнопки мыши
// ---
VARIANT_BOOL STDMETHODCALLTYPE DocumentFrameEvent::XDocumentFrameNotify::MouseDown( 
    /* [in] */ short nButton,
    /* [in] */ short nShiftState,
    /* [in] */ long x,
    /* [in] */ long y ) {
	METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify)
  pThis->down = true;
  return true;
}


//-----------------------------------------------------------------------------
// Отпустили кнопку мыши
// ---
VARIANT_BOOL STDMETHODCALLTYPE DocumentFrameEvent::XDocumentFrameNotify::MouseUp( 
    /* [in] */ short nButton,
    /* [in] */ short nShiftState,
    /* [in] */ long x,
    /* [in] */ long y ) {
	METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify) // Сместиться к началу класса
  pThis->down = false; 
  return true;
}


//-----------------------------------------------------------------------------
// двойной клик 
// ---
VARIANT_BOOL STDMETHODCALLTYPE DocumentFrameEvent::XDocumentFrameNotify::MouseDblClick( 
    /* [in] */ short nButton,
    /* [in] */ short nShiftState,
    /* [in] */ long x,
    /* [in] */ long y ) {
  return true;
}


//-----------------------------------------------------------------------------
// Начало отрисовки документа  
// ---
VARIANT_BOOL STDMETHODCALLTYPE DocumentFrameEvent::XDocumentFrameNotify::BeginPaintGL( long drawMode )
{
	METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify) // Сместиться к началу класса
  VARIANT_BOOL res = TRUE;
  if ( drawMode == vm_Shaded ) 
  {
    IDocument3DPtr doc3D( ksGetActive3dDocument(), false/*AddRef*/ );
    IPartPtr pTopPart( doc3D ? doc3D->GetPart(pTop_Part) : NULL, false/*AddRef*/ );
 
    if ( (bool)doc3D && (bool)pTopPart ) 
    {
      // Стираем старое изображение
      ::glPushAttrib( GL_ENABLE_BIT | GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT );
      
      ::glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );    
      ::glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
      ::glDisable( GL_LIGHTING );
      ::glEnable( GL_DEPTH_TEST );

      int start = GetTickCount();
      if ( doc3D->IsDetail() ) 
        RedrawModelFaces( pTopPart, pTopPart );            // Анализ триангуляции детали
      else
      {
        IFeaturePtr partFeature( pTopPart->GetFeature(), false/*AddRef*/ );
        if ( partFeature )
          RecursiveDraw( pTopPart, partFeature );          // Рекурсивный обход объектов сборки
      }
      int end = GetTickCount();
      TRACE( _T("ClosePaintGL %i"), end - start );
/*
      glBegin(GL_LINES);
        glColor3d(0.0, 1.0, 0.0);
        glVertex3d( 0, 0, 0 );
        glVertex3d( 0, 1000, 0 );   
      glEnd();
 
*/      

     IDocumentFramePtr documentFrame(pThis->m_params.iObj);
     long Left, Right, Bottom, Top;
     documentFrame->GetWorkAreaRect( &Left, &Top, &Right, &Bottom );
      
           
     glMatrixMode(GL_PROJECTION);
     glPushMatrix();
     glLoadIdentity();
     glOrtho(Left, Right, Top, Bottom, -1.0, 1.0);
     glMatrixMode(GL_MODELVIEW);
     glPushMatrix();
     
     	
     glLoadIdentity();
     glDisable(GL_LIGHTING);

      glBegin(GL_QUADS);
         glColor3d(1.0, 0, 1.0);
         glVertex2d( 615 ,680   );
         glVertex2d( 815 ,680   ); 
         glVertex2d( 815 ,880   );  
         glVertex2d( 615 ,880   );
      glEnd();

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    
    glMatrixMode(GL_MODELVIEW);

      ::glEnable( GL_LIGHTING );
      
      ::glPopAttrib();
      res = FALSE;
    }

//     Если нужно изменить габариты документа, то нужно взвести флаг GabaritModifying
//     В результате перед следующей перерисовкой получем сообщение AddGabarit
//      IDocumentFramePtr documentFrame(pThis->m_params.iObj);
//      if ( documentFrame ) {
//        documentFrame->SetGabaritModifying();
//      }


  }

  return res;
}


//-----------------------------------------------------------------------------
// Завершение отрисовки документа
// ---
VARIANT_BOOL STDMETHODCALLTYPE DocumentFrameEvent::XDocumentFrameNotify::ClosePaintGL(  long drawMode )
{
	METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify) // Сместиться к началу класса


/*
  if ( drawMode == vm_Shaded ) 
  {
    IDocument3DPtr doc3D( ksGetActive3dDocument(), false );
    if ( (bool)doc3D ) 
    {
//      ::glClearColor( 1.0f, 1.0f, 1.0f, 1.0f);    
//      ::glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
//      ::glDisable( GL_LIGHTING );
      int start = GetTickCount();
      if ( doc3D->IsDetail() ) 
      {
        IPartPtr pPart( doc3D->GetPart( pTop_Part ) , false );
        if ( pPart ) 
          RedrawModelFaces( pPart, pPart );
      }
      else
      {
        IPartPtr pTopPart( doc3D->GetPart( pTop_Part ) , false );
        IFeaturePtr partFeature( pTopPart->GetFeature(), false );
        if ( partFeature )
        {
          RecursiveDraw( pTopPart, partFeature );
        }
      }
      int end = GetTickCount();
      TRACE( _T("ClosePaintGL %i"), end - start );
//      ::glEnable( GL_LIGHTING );
    }
//      IDocumentFramePtr documentFrame(pThis->m_params.iObj);
//      if ( documentFrame ) {
//        documentFrame->SetGabaritModifying();
//    }

  }
*/
  return true;
}


//-----------------------------------------------------------------------------
// Добавление габарита 
// ---
VARIANT_BOOL STDMETHODCALLTYPE DocumentFrameEvent::XDocumentFrameNotify::AddGabarit( IUnknown __RPC_FAR *gabObj)
{
   METHOD_PROLOGUE(DocumentFrameEvent, DocumentFrameNotify)  // Сместиться к началу класса
/*  IGabaritObjectPtr gabaritObject(gabObj);
  if(gabaritObject){
    double x1;
    double y1;
    double z1;
    double x2;
    double y2;
    double z2;
    VARIANT_BOOL res = gabaritObject->GetCurrentGabarit( 0, &x1, &y1, &z1, &x2, &y2, &z2 );
    if ( res ) {
      x2 += 1000;    
      xMax = x2;
      res = gabaritObject->AddGabarit( x1, y1, z1, x2, y2, z2 );
    }
  }
*/
  return false;
}


//-----------------------------------------------------------------------------
// Активизвация
// ---
VARIANT_BOOL STDMETHODCALLTYPE DocumentFrameEvent::XDocumentFrameNotify::Activate( void) 
{
  return true;
}


//-----------------------------------------------------------------------------
// Деактивизация
// ---
VARIANT_BOOL STDMETHODCALLTYPE DocumentFrameEvent::XDocumentFrameNotify::Deactivate( void )
{
  return true;
}


//-----------------------------------------------------------------------------
// Закрытие окна
// ---
VARIANT_BOOL STDMETHODCALLTYPE DocumentFrameEvent::XDocumentFrameNotify::CloseFrame( void ) 
{
  METHOD_PROLOGUE(DocumentFrameEvent, DocumentFrameNotify)  // Сместиться к началу класса
  pThis->Disconnect();
  return true;
}


//-------------------------------------------------------------------------------
// Перемещение мыши
// ---
VARIANT_BOOL STDMETHODCALLTYPE DocumentFrameEvent::XDocumentFrameNotify::MouseMove(
           short nShiftState,
           long x,
           long y )
{
  METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify )
  return true; 
}


//-----------------------------------------------------------------------------
//
// ---
VARIANT_BOOL STDMETHODCALLTYPE DocumentFrameEvent::XDocumentFrameNotify::ShowOcxTree (
                                                    IUnknown * tree,
                                                    VARIANT_BOOL show )
{
  METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify )
  return true; 
}


//-------------------------------------------------------------------------------
// frBeginPaintTmpObjects          - Начало отрисовки временных объектов
// ---
VARIANT_BOOL DocumentFrameEvent::XDocumentFrameNotify::BeginPaintTmpObjects() {
  METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify )
  return true;
}


//-------------------------------------------------------------------------------
// frClosePaintTmpObjects          - Конец отрисовки временных объектов
// ---
VARIANT_BOOL DocumentFrameEvent::XDocumentFrameNotify::ClosePaintTmpObjects() {
  METHOD_PROLOGUE_EX_(DocumentFrameEvent, DocumentFrameNotify )
  return true;
}
