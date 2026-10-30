unit DocumentFrameEvents;

interface
uses
  Windows,
  cBaseEvents,
  ks2DCOM_TLB,
  ks3DCOM_TLB,
  LTool3D,
  ksConstTLB,
  LDefin3D,
  ActiveX,
  Libtool,
  Opengl,
  LtDefine,
{$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 14 }
  Variants,
{$IFEND}
{$ENDIF CONDITIONALEXPRESSIONS}
  ksApi7;

type

////////////////////////////////////////////////////////////////////////////////
// DocumentFrameEvent  - обрабокчик событий от окна документа
//
DocumentFrameEvent = class ( cBaseEvent, IDocumentFrameNotify )
public

  constructor Create( var frame : IDocumentFrame; _docRef : Reference ); overload;
  destructor  Destroy(); override;
  function    Advise(): boolean; override;

protected
  // Функция должна возвращать true если метод notifyType обрабатывается интерфейсом
  function IsNotifyProcess(notifyType: SYSINT): WORDBOOL; virtual; stdcall;
  // frBeginPaint = 1 Начало отрисовки документа.
  function  BeginPaint(const paintObj: IUnknown): WordBool; virtual; stdcall;
  // frClosePaint = 2 Конец отрисовки документа.
  function  ClosePaint(const paintObj: IUnknown): WordBool; virtual; stdcall;
  // frMouseDown  = 3 Нажатие кнопки мыши.
  function  MouseDown(nButton: Smallint; nShiftState: Smallint; x: Integer; y: Integer): WordBool; virtual; stdcall;
  // frMouseUp = 4 Отпускание кнопки мыши.
  function  MouseUp(nButton: Smallint; nShiftState: Smallint; x: Integer; y: Integer): WordBool; virtual; stdcall;
  // frMouseDblClick = 5 Двойной клик кнопки мыши.
  function  MouseDblClick(nButton: Smallint; nShiftState: Smallint; x: Integer; y: Integer): WordBool; virtual; stdcall;
  // frBeginPaintGL = 6 Начало создания листа в контексте OpenGL.
  function  BeginPaintGL(drawMode: Integer): WordBool; virtual; stdcall;
  // frClosePaintGL = 7 Окончание создания листа в контексте OpenGL.
  function  ClosePaintGL(drawMode: Integer): WordBool; virtual; stdcall;
  // frAddGabarit = 8 Определение габаритов документа.
  function  AddGabarit(const gabObj: IUnknown): WordBool; virtual; stdcall;
  // frActivate = 9 Окно активизировалось.
  function  Activate: WordBool; virtual; stdcall;
  // frDeactivate = 10 Окно деактивизировалось.
  function  Deactivate: WordBool; virtual; stdcall;
  // frCloseFrame = 11 Закрытие окна.
  function  CloseFrame: WordBool; virtual; stdcall;
  // frMouseMove = 12 Движение мыши.
  function  MouseMove(nShiftState: Smallint; x: Integer; y: Integer): WordBool; virtual; stdcall;
  // frShowOcxTree = 13 Показалось\скрылось дерево
  function  ShowOcxTree(const tree: IUnknown; show: WordBool): WordBool; virtual; stdcall;

  function BeginPaintTmpObjects: WordBool; virtual; stdcall;
  function ClosePaintTmpObjects: WordBool; virtual; stdcall;


end;

  function NewDocumentFrameEvent( var frame : IDocumentFrame; doc : reference; redrawType : Integer ) : DocumentFrameEvent;
  procedure RecursiveDraw( var pTopPart : IPart; var coll : IFeatureCollection );

implementation

var
  xMax : double = 0;
  frameEventRedrawType : integer;

constructor DocumentFrameEvent.Create( var frame : IDocumentFrame; _docRef : Reference );
var
  unk : IUnknown;
begin
  unk := frame As IUnknown;
  inherited CreateByObj( ntDocumentFrameNotify, unk, _docRef );
   m_params.pContainer := _docRef;
end;

destructor DocumentFrameEvent.Destroy();
begin
  inherited Destroy;
end;

//------------------------------------------------------------------------------
// Advise
//---
function DocumentFrameEvent.Advise() : boolean;
begin
  if not m_advise and ( m_params.ifType <> 0 ) then
    m_advise := boolean( ksConnectionAdvise( @m_params, PIUnknown(IDocumentFrameNotify(self)) ) );
	Result := m_advise;
end;

function DocumentFrameEvent.IsNotifyProcess( notifyType: SYSINT ) : WORDBOOL;
begin
  Result := ( notifyType >= frBeginPaint ) And ( notifyType <= frCloseFrame )
end;

// frBeginPaint = 1 Начало отрисовки документа.
function DocumentFrameEvent.BeginPaint(const paintObj: IUnknown): WordBool;
begin
  Result := true;
end;

// frClosePaint = 2 Конец отрисовки документа.
function DocumentFrameEvent.ClosePaint(const paintObj: IUnknown): WordBool;
{var
  paintObject : IPaintObject;
  a11, a12, a13, a14, a21, a22, a23, a24 : Double;
  Xmm, Ymm, Zmm : Double;
  f             : OLE_HANDLE;
  _hWnd         : HWND;
  _hDC          : HDC;
  Xlp, Ylp      : Integer;
}
begin
{  paintObject := paintObj As IPaintObject;
  if paintObject <> nil then
  begin
    paintObject.GetTransformMatrix( a11, a12, a13, a14, a21, a22, a23, a24 );
//    Xlp := Round( Xmm * a11 + Ymm * a12 + Zmm * a13 + a14 );
//    Ylp := Round( Xmm * a21 + Ymm * a22 + Zmm * a23 + a24 );
    f := paintObject.GetHWND();
    _hWnd := f;
    _hDC  := GetDC(_hWnd);
    Xmm   := 50;
    Ymm   := 30;
    Zmm   := 10;
    Xlp   := Round(Xmm * a11 + Ymm * a12 + Zmm * a13 + a14);
    Ylp   := Round(Xmm * a21 + Ymm * a22 + Zmm * a23 + a24);
    MoveToEx( _hDC, Xlp, Ylp, nil );
    Xmm := xMax;
    Xlp := Round(Xmm * a11 + Ymm * a12 + Zmm * a13 + a14);

    LineTo( _hDC, Xlp, Ylp );
    ReleaseDC( _hWnd, _hDC );
  end;
}
  Result := true;
end;

// frMouseDown  = 3 Нажатие кнопки мыши.
function DocumentFrameEvent.MouseDown(nButton: Smallint; nShiftState: Smallint;
                                      x: Integer; y: Integer): WordBool;
begin
  Result := true;
end;

// frMouseUp = 4 Отпускание кнопки мыши.
function DocumentFrameEvent.MouseUp(nButton: Smallint; nShiftState: Smallint; x: Integer; y: Integer): WordBool;
begin
  Result := true;
end;

// frMouseDblClick = 5 Двойной клик кнопки мыши.
function DocumentFrameEvent.MouseDblClick(nButton: Smallint; nShiftState: Smallint; x: Integer; y: Integer): WordBool;
begin
  Result := true;
end;

//-------------------------------------------------------------------------------
// Разукрасим грани
// ---
procedure RedrawFace( var topPart: IPart; var nextPart : IPart; var fDef0 : IFaceDefinition );
var
  transform      : Boolean;
  i, j,
  pointsCount,
  trianglesCount,
  normalsCount,
  index         : Integer;
  points,
  indexes,
  normals        : OleVariant;
  tess           : ITessellation;
  x, y, z        : Double;
begin
  transform := ( topPart <> nil ) And ( topPart <> nextPart );
  if fDef0 <> nil then
  begin
    tess := ITessellation( fDef0.GetTessellation() );
    if tess <> nil then
    begin
      tess._Release();
      // Новый метод получения параметров треангуляции
      tess.GetFacetPoints( points, indexes );
      tess.GetFacetNormals( normals );
      if ( ( VarType( indexes ) = (VT_ARRAY Or VT_I4) )   And
           ( VarType( points  ) = (VT_ARRAY Or VT_R8) )   And
           ( VarType( normals ) = (VT_ARRAY Or VT_R8) ) ) then
      begin
        // массив должен быть одномерный и количество точек должно быть кратно трем
        pointsCount    := ( VarArrayHighBound( points,  1 ) + 1 ) div 3;
        trianglesCount := ( VarArrayHighBound( indexes, 1 ) + 1 ) div 3;
        normalsCount   := ( VarArrayHighBound( normals, 1 ) + 1 ) div 3;
        if ( pointsCount > 0 ) And ( trianglesCount > 0 ) And ( normalsCount > 0 ) then
        begin
          // Добавить точку в определение новой кривой
          j := 0;
          for i := 0 to trianglesCount -1 do
          begin
            glBegin( GL_TRIANGLES );
              index := indexes[j] * 3;
              x := points[index];
              inc( index );
              y := points[index];
              inc( index );
              z := points[index];
              if transform then
                // Перевод координат из системы координат детали в систему координат сборки
                topPart.TransformPoint( x, y, z, nextPart );
              glColor3d( 1.0, 0, 0.0 );
              glVertex3d( x, y, z );

              index := indexes[j] * 3;
              inc( j );
              x := normals[index];
              inc( index );
              y := normals[index];
              inc( index );
              z := normals[index];
              glNormal3d( x, y, z );

              index := indexes[j] * 3;
              x := points[index];
              inc( index );
              y := points[index];
              inc( index );
              z := points[index];
              if transform then
                // Перевод координат из системы координат детали в систему координат сборки
                topPart.TransformPoint( x, y, z, nextPart );
              glColor3d( 0.0, 1.0, 0 );
              glVertex3d( x, y, z );

              index := indexes[j] * 3;
              inc( j );
              x := normals[index];
              inc( index );
              y := normals[index];
              inc( index );
              z := normals[index];
              glNormal3d( x, y, z );

              index := indexes[j] * 3;
              x := points[index];
              inc( index );
              y := points[index];
              inc( index );
              z := points[index];
              if  transform then
                // Перевод координат из системы координат детали в систему координат сборки
                topPart.TransformPoint( x, y, z, nextPart );
              glColor3d( 0, 0.0, 1.0 );
              glVertex3d( x, y, z );

              index := indexes[j] * 3;
              inc( j );
              x := normals[index];
              inc( index );
              y := normals[index];
              inc( index );
              z := normals[index];
              glNormal3d( x, y, z );

            glEnd();
          end;
        end
      end
    end
  end
end;


//-------------------------------------------------------------------------------
// Разукрасим грани
// ---
procedure RedrawFaceByEntity( var topPart: IPart; var nextPart : IPart; var face : IEntity );
var
  fDef0          : IFaceDefinition;
  pUnk           : IUnknown;
begin
  if ( face <> nil ) And ( face.IsCreated() <> 0 ) then
  begin
    pUnk := IUnknown( face.GetDefinition() );
    fDef0 := pUnk As IFaceDefinition;
    if fDef0 <> nil then
    begin
      fDef0._Release();
      RedrawFace( topPart, nextPart, fDef0 );
    end
  end
end;

//-------------------------------------------------------------------------------
// Разукрасим грани
// ---
procedure RedrawFaces( var topPart: IPart; var nextPart : IPart; var faces : IEntityCollection );
var
  facesCount, ie : Integer;
  face           : IEntity;
begin
  facesCount := faces.GetCount();
  for ie := 0 to facesCount - 1 do
  begin
    face := IEntity( faces.GetByIndex(ie) );
    face._Release();
    RedrawFaceByEntity( topPart, nextPart, face );
  end
end;

//-------------------------------------------------------------------------------
// Разукрасим грани
// ---
procedure RedrawFacesByFaceCollection( var topPart: IPart; var nextPart : IPart; var faces : IFaceCollection );
var
  facesCount, ie : Integer;
  face           : IFaceDefinition;
begin
  facesCount := faces.GetCount();
  for ie := 0 to facesCount - 1 do
  begin
    face := IFaceDefinition( faces.GetByIndex(ie) );
    face._Release();
    RedrawFace( topPart, nextPart, face );
  end
end;

//-------------------------------------------------------------------------------
//
// ---
procedure RedrawModelFaces( var topPart : IPart; var nextPart : IPart );
var
  faces       : IEntityCollection;
  partFeature,
  nextFeature : IFeature;
  featureColl : IFeatureCollection;
  i, count    : Integer;
  bodyColl    : IBodyCollection;
  faceColl    : IFaceCollection;
  body        : IBody;
begin
  if ( nextPart <> nil ) And ( nextPart.IsDetail()   <> 0 )
                         And ( nextPart.GetHidden()   = 0 )
                         And ( nextPart.GetExcluded() = 0 ) then
  begin
    case frameEventRedrawType of

      0 : // Получаем грани с детали
        begin
          faces := IEntityCollection( nextPart.EntityCollection(o3d_face) );
          if ( faces <> nil ) then
          begin
            faces._Release();
            RedrawFaces( topPart, nextPart, faces );
          end
        end;

      1 : // Получаем грани с операций
        begin
          partFeature := IFeature( nextPart.GetFeature() );
          if partFeature <> nil then
          begin
            // Получить коллекцию листов детали
            featureColl := IFeatureCollection( partFeature.SubFeatureCollection( 0,  // не выдавать скрытые объекты
                                                                                 1 ) );
            if ( featureColl <> nil ) then
            begin
              featureColl._Release;
              count := featureColl.GetCount();
              for i := 0 to count - 1 do
              begin
                nextFeature := IFeature( featureColl.GetByIndex(i) );
                nextFeature._Release;
                faces := IEntityCollection( nextFeature.EntityCollection(o3d_face) );
                if ( faces <> nil ) then
                begin
                  faces._Release;
                  RedrawFaces( topPart, nextPart, faces );
                end
              end;
            end;
          end
        end;

      2 : // Получение коллекции граней с коллекции тел
        begin
          bodyColl := IBodyCollection( nextPart.BodyCollection() );
          if ( bodyColl <> nil ) then
          begin
            bodyColl._Release;
            count := bodyColl.GetCount();
            for i := 0 to count - 1 do
            begin
              body := IBody( bodyColl.GetByIndex(i) );
              if ( body <> nil ) then
              begin
                body._Release;
                faceColl := IFaceCollection( body.FaceCollection() );
                if ( faceColl <> nil ) then
                begin
                  faceColl._Release;
                  RedrawFacesByFaceCollection( topPart, nextPart, faceColl );
                end
              end;
            end
          end
        end;
      3 : // Получение коллекции граней с коллекции тел
        begin
          body :=  IBody( nextPart.GetMainBody() );
          if ( body <> nil ) then
          begin
            faceColl := IFaceCollection( body.FaceCollection() );
            if ( faceColl <> nil ) then
            begin
              faceColl._Release;
              RedrawFacesByFaceCollection( topPart, nextPart, faceColl );
            end;
          end;
        end;
    end;
  end
end;


//-------------------------------------------------------------------------------
// Рекурсивный обход объектов сборки
// ---
procedure RecursiveDrawOnFeature( var pTopPart : IPart; var nextFeature : IFeature );
var
  unkObj, unkDef : IUnknown;
  pPart, parent  : IPart;
  featColl       : IFeatureCollection;
  entityColl     : IEntityCollection;
  entity         : IEntity;
  count, i       : Integer;
  pFace          : IFaceDefinition;
begin
  if ( pTopPart <> nil ) And ( nextFeature <> nil ) then
  begin
    unkObj := IUnknown( nextFeature.GetObject() );
    if unkObj <> nil then
      unkObj._Release;
    case nextFeature.GetType() of
      o3d_part:
      begin
        pPart :=  unkObj As IPart;
        if ( pPart <> nil ) And ( pPart.IsDetail() <> 0 ) then
          RedrawModelFaces( pTopPart, pPart )
        else
        begin
          // Получить коллекцию листов сборки
          featColl := IFeatureCollection( nextFeature.SubFeatureCollection(  0     // не выдавать скрытые объекты
                                                                           , 1) ); // выдавать библиотечные объекты
          if featColl <> nil then
          begin
            featColl._Release;
            RecursiveDraw( pTopPart, featColl ); // Рекурсивный обход по листам сборки
          end;
        end;
      end;

      o3d_entity:
      begin
        entity := unkObj As IEntity;
        if ( entity <> nil ) and ( frameEventredrawType = 1 ) then
        begin
          if ( entity.GetExcluded() = 0 ) And
             ( entity.GetHidden()   = 0 ) then
          begin
            // Если операция создана на уровне сборки или подсборки то для нее тоже нужно получить грани
            // Получение колекций граней для сборочных операций
            parent := IPart( entity.GetParent() );
            if ( parent <> nil ) then
            begin
              parent._Release;
              if parent.IsDetail() = 0 then
              begin
                entityColl := IEntityCollection( nextFeature.EntityCollection(o3d_face) );
                if ( entityColl <> nil ) then
                begin
                  entityColl._Release;
                  count := entityColl.GetCount;
                  for i := 0 to count - 1 do
                  begin
                    // грани сборочной операции могут принадлежать разным деталям
                    entity := IEntity( entityColl.GetByIndex(i) );
                    if ( entity <> nil ) then
                    begin
                      entity._Release;
                      parent := IPart( entity.GetParent() );
                      if ( parent <> nil ) then
                      begin
                        unkDef := IUnknown( entity.GetDefinition() );
                        if ( unkDef <> nil ) then
                        begin
                          unkDef._Release;
                          pFace  := unkDef As IFaceDefinition;
                          if ( pFace <> nil ) then
                          begin
                            RedrawFace( pTopPart, parent, pFace );
                          end
                        end;
                      end;
                    end;
                  end;
                end
              end;
            end
          end
        end;
        featColl := IFeatureCollection( nextFeature.SubFeatureCollection( 0, 1 ) );
        if featColl <> nil then
        begin
          featColl._Release;
          RecursiveDraw( pTopPart, featColl );
        end
      end;

      o3d_unknown:
      begin
        // Неопознанный объект берем SubFeatureCollection
        featColl := IFeatureCollection( nextFeature.SubFeatureCollection( 0, 0 ) );
        if featColl <> nil then
        begin
          featColl._Release();
          RecursiveDraw( pTopPart, featColl );
        end;
      end
    end
  end
end;


//-------------------------------------------------------------------------------
// Обход объектов коллекции
// ---
procedure RecursiveDraw( var pTopPart : IPart; var coll : IFeatureCollection );
var
  i, count    : integer;
  nextFeature : IFeature;
begin
  if coll <> nil then
  begin
    count := coll.GetCount();
    for i := 0 to count - 1 do
    begin
      nextFeature := IFeature( coll.GetByIndex(i) );
      if ( nextFeature <> nil ) then
      begin
        nextFeature._Release();
        if nextFeature.GetExcluded() = 0  then
          RecursiveDrawOnFeature( pTopPart, nextFeature );
      end
    end
  end
end;


// frBeginPaintGL = 6 Начало создания листа в контексте OpenGL.
function DocumentFrameEvent.BeginPaintGL(drawMode: Integer): WordBool;
var
  doc3D       : IDocument3D;
  pTopPart    : IPart;
  partFeature : IFeature;
begin
  Result := true;
  if drawMode = vm_Shaded then
  begin
    doc3D := IDocument3D( ksGetActive3dDocument() );
    if ( doc3D <> nil ) then
    begin
      doc3D._Release;
      // Запомним состояние флагов
      glPushAttrib( GL_ENABLE_BIT Or GL_DEPTH_BUFFER_BIT Or GL_COLOR_BUFFER_BIT );

      glClearColor( 1.0, 1.0, 1.0, 1.0 );
      glClear( GL_COLOR_BUFFER_BIT or GL_DEPTH_BUFFER_BIT );
      glDisable( GL_LIGHTING );
      glEnable( GL_DEPTH_TEST );
      pTopPart := IPart( doc3D.GetPart(pTop_Part) );
      if pTopPart <> nil then
      begin
        pTopPart._Release;
        if doc3D.IsDetail() <> 0 then
          RedrawModelFaces( pTopPart, pTopPart )            // Анализ треангуляции детали
        else
        begin
          partFeature := IFeature( pTopPart.GetFeature() );
          if ( partFeature <> nil ) then
          begin
            partFeature._Release;
            RecursiveDrawOnFeature( pTopPart, partFeature );
          end
        end
      end;
      doc3D := nil;
      Result:= false;
      glEnable( GL_LIGHTING );
      
      // Восстановим состояние флагов
      glPopAttrib();
    end;
  end
end;

// frClosePaintGL = 7 Окончание создания листа в контексте OpenGL.
function DocumentFrameEvent.ClosePaintGL(drawMode: Integer): WordBool;
begin
  Result := true;
end;

// frAddGabarit = 8 Определение габаритов документа.
function DocumentFrameEvent.AddGabarit(const gabObj: IUnknown): WordBool;
  var
    gabaritObject : IGabaritObject;
    x1, y1, z1    : Double;
    x2, y2, z2    : Double;
begin
  gabaritObject := gabObj As IGabaritObject;
  Result := true;
  if gabaritObject <> nil then
  begin
    Result := gabaritObject.GetCurrentGabarit( 0,  x1, y1, z1, x2, y2, z2 );
    if Result then
    begin
      x2   := x2 + 1000;
      xMax := x2;
      Result := gabaritObject.AddGabarit( x1, y1, z1, x2, y2, z2 );
    end
  end
end;

// frActivate = 9 Окно активизировалось.
function DocumentFrameEvent.Activate: WordBool;
begin
  Result := true;
end;

// frDeactivate = 10 Окно деактивизировалось.
function DocumentFrameEvent.Deactivate: WordBool;
begin
  Result := true;
end;

// frCloseFrame = 11 Закрытие окна.
function DocumentFrameEvent.CloseFrame: WordBool;
begin
  Unadvise;
  Result := true;
end;

  // frMouseMove = 12 Движение мыши.
function  DocumentFrameEvent.MouseMove(nShiftState: Smallint; x: Integer; y: Integer): WordBool;
begin
  Result := true;
end;

// frShowOcxTree = 13 Показалось\скрылось дерево
function DocumentFrameEvent.ShowOcxTree(const tree: IUnknown; show: WordBool): WordBool; stdcall;
begin
  Result := true;
end;

function DocumentFrameEvent.BeginPaintTmpObjects: WordBool; stdcall;
begin
  Result := true;
end;

function DocumentFrameEvent.ClosePaintTmpObjects: WordBool; stdcall;
begin
  Result := true;
end;


function NewDocumentFrameEvent(  var frame : IDocumentFrame; doc : reference; redrawType : Integer ) : DocumentFrameEvent;
var
  unk : IUnknown;
begin
  Result := nil;
  if doc <> 0 then begin
    unk := frame As IUnknown;
		if cBaseEvent.FindEvents( ntDocumentFrameNotify, 0, -1, unk ) = nil then begin
			Result := DocumentFrameEvent.Create( frame, doc );
			if not Result.Advise() then begin
        Result.Free;
				Result := nil;
			end
		end;
    frameEventRedrawType := redrawType;
	end
end;

end.
