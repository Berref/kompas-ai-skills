// testView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
#include "test.h"

#include "testDoc.h"
#include "testView.h"
#include "DocumentEvent.h"

#include <SArray.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestView

IMPLEMENT_DYNCREATE(CTestView, CView)

BEGIN_MESSAGE_MAP(CTestView, CView)
  ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
  //{{AFX_MSG_MAP(CTestView)
  ON_WM_CREATE()
  ON_WM_DESTROY()
  ON_WM_SIZE()
  //}}AFX_MSG_MAP
  // Standard printing commands
  ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
  ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
  ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
  ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
  ON_COMMAND(ID_FILE_NEW, OnFileNew)
  ON_COMMAND(ID_EDIT_CUT, OnFileReload)
END_MESSAGE_MAP()

BEGIN_EVENTSINK_MAP(CTestView, CView)
  ON_EVENT(CTestView, IDC_KOMPAS_CTRL, 1 /*KgMouseDown*/, OnKgMouseDownKgaxctrl, VTS_I2 VTS_I2 VTS_I4 VTS_I4 VTS_PBOOL)
  ON_EVENT(CTestView, IDC_KOMPAS_CTRL, 10 /*KgKeyDown*/, OnKgKeyDownKgaxctrl, VTS_PI4 VTS_I2)
  ON_EVENT(CTestView, IDC_KOMPAS_CTRL, 11 /*KgKeyUP*/, OnKgKeyUpKgaxctrl, VTS_PI4 VTS_I2)
  ON_EVENT(CTestView, IDC_KOMPAS_CTRL, 12 /*KgKeyPress*/, OnKgKeyPressKgaxctrl, VTS_PI4)
END_EVENTSINK_MAP()

void CTestView::OnKgMouseDownKgaxctrl(short nButton, short nShiftState, long x, long y, BOOL FAR* proceed) {
  if (nButton == 2) {
    ::MessageBox(0, _T("OnKgMouseDownKgaxctrl"), _T("EVENT"), MB_OK);
    if (proceed)
      *proceed = FALSE;
  }
  else {
    if (proceed)
      *proceed = TRUE;
  }
}


void CTestView::OnKgKeyDownKgaxctrl(long FAR* nButton, short nShiftState)
{
  if (nButton) {
    ::MessageBox(0, _T("OnKgKeyDownKgaxctrl"), _T("EVENT"), MB_OK);
    if (*nButton == VK_F1 && nShiftState == 0)
      *nButton = 0;
  }
}

void CTestView::OnKgKeyUpKgaxctrl(long FAR* nButton, short nShiftState)
{
  if (nButton) {
    ::MessageBox(0, _T("OnKgKeyUpKgaxctrl"), _T("EVENT"), MB_OK);
    if (*nButton == VK_F1 && nShiftState == 0)
      *nButton = 0;
  }
}

void CTestView::OnKgKeyPressKgaxctrl(long FAR* nButton)
{
  if (nButton) {
    ::MessageBox(0, _T("OnKgKeyPressKgaxctrl"), _T("EVENT"), MB_OK);
    if (*nButton == VK_F1)
      *nButton = 0;
  }
}

/////////////////////////////////////////////////////////////////////////////
// CTestView construction/destruction

CTestView::CTestView()
{
  // TODO: add construction code here

}

CTestView::~CTestView()
{
}

BOOL CTestView::PreCreateWindow(CREATESTRUCT& cs)
{
  // TODO: Modify the Window class or styles here by modifying
  //  the CREATESTRUCT cs
  cs.style &= ~WS_TABSTOP;
  cs.style |= (WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS);

  cs.dwExStyle &= ~WS_EX_CLIENTEDGE;

  return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTestView drawing

void CTestView::OnDraw(CDC* pDC)
{
  CTestDoc* pDoc = GetDocument();
  ASSERT_VALID(pDoc);
  // TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTestView printing

BOOL CTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
  // default preparation
  return DoPreparePrinting(pInfo);
}

void CTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
  // TODO: add extra initialization before printing
}

void CTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
  // TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTestView diagnostics

#ifdef _DEBUG
void CTestView::AssertValid() const
{
  CView::AssertValid();
}

void CTestView::Dump(CDumpContext& dc) const
{
  CView::Dump(dc);
}

CTestDoc* CTestView::GetDocument() // non-debug version is inline
{
  ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestDoc)));
  return (CTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestView message handlers

void CTestView::OnInitialUpdate()
{
  CView::OnInitialUpdate();
}

int CTestView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
  if (CView::OnCreate(lpCreateStruct) == -1)
    return -1;

  // Create the style
  DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_TABSTOP | LVS_REPORT;
  if (m_KompasCtrl.Create(_T(""), dwStyle, CRect(0, 0, 0, 0), this, IDC_KOMPAS_CTRL)) {
    m_KompasCtrl->PutDocumentType(vt_3DPart); // Модель
    return 0;
  }
  else
    return -1;
}

void CTestView::OnFileOpen()
{
  KompasObjectPtr pKompas = m_KompasCtrl->GetKompasObject();
  if (pKompas)
  {
    CString strFilter = _T("Файлы КОМПАС(*.cdw, *.frw,*.m3d,*.a3d,*.t3d,*.spw,*.kdw)|*.cdw;*.frw;*.m3d;*.a3d;*.t3d;*.spw;*.kdw");
    CString filename = (LPCTSTR)pKompas->ksChoiceFile(_T("cdw"), LPCTSTR(strFilter), 1);
    if (!filename.IsEmpty() && m_KompasCtrl->TestLoadDocument((LPCTSTR)filename) == 1)
    {
      IApplicationPtr api7(pKompas->ksGetApplication7());
      if (api7)
        api7->HideMessage = ksHideMessageNo;
      m_KompasCtrl->AddDocument((LPCTSTR)filename);
    }
  }
}

//------------------------------------------------------------------------------
// получит расширене файла без точки 
//---
LPCTSTR GetFileExtension(LPCTSTR name) {
  if (name) {
    LPCTSTR ext = ::_tcsrchr(name, _T('.'));

    if (ext && *(ext + 1) != '\0')
      return ext + 1;
  }
  return NULL;
}

UINT GetFileName(LPCTSTR lpszPathName, _Out_writes_opt_(nMax) LPTSTR lpszTitle, UINT nMax)
{
  // always capture the complete file name including extension (if present)
  LPTSTR lpszTemp = ::PathFindFileName(lpszPathName);

  // otherwise copy it into the buffer provided
  Checked::tcsncpy_s(lpszTitle, nMax, lpszTemp, _TRUNCATE);
  return 0;
}

// #81108
CString GetTmpFileName(KompasObjectPtr& pKompas, const CString& fileName, LPCTSTR newExt)
{
  CString ext(GetFileExtension(fileName));
  TCHAR oldFileName[MAX_PATH] = { 0 };
  GetFileName(fileName, oldFileName, MAX_PATH);
  // #81108         ext = _T(".") + ext;
  // #81108         res = fileName;
  // #81108         res.Replace( ext, _T("tt.frw") );
  Checked::tcscat_s(oldFileName, MAX_PATH, newExt);
  CString res = (LPCTSTR)pKompas->ksSystemPath(sptTEMP_FILES);
  if (res.Right(1) != _T("\\"))
    res += _T("\\");
  res += oldFileName;
  return res;
}

//-----------------------------------------------------------------------------
// Изменение слоя объекта
// ---
void SetLayer(KompasObjectPtr& kompas,
              ksDocument2DPtr& doc2D,
              ksDimTextParamPtr& textParam, reference gr, long i, bool changeAutoNom)
{
  ksIteratorPtr itObj = kompas->GetIterator();
  if (itObj)
  {
    char buff[20];
    ksDoubleValuePtr   dValue(kompas->GetParamStruct(ko_DoubleValue));
    ksTextLineParamPtr lineParam(kompas->GetParamStruct(ko_TextLineParam));
    ksTextItemParamPtr textItem(kompas->GetParamStruct(ko_TextItemParam));

    ksDynamicArrayPtr dimArray(lineParam->GetTextItemArr());
    dimArray->ksAddArrayItem(-1, textItem);

    itObj->ksCreateIterator(ALL_OBJ, gr);
    reference objRef = itObj->ksMoveIterator("F");
    double value = 0;
    while (objRef)
    {
      doc2D->ksChangeObjectLayer(objRef, i);
      if (changeAutoNom) // если масштаб вида отличен от 1:1 снимаем автонаминал у размеров
      {
        long type = doc2D->ksGetObjParam(objRef, NULL, ALLPARAM);
        switch (type)
        {
          case LDIMENSION_OBJ:
            //          case ADIMENSION_OBJ       :
          case DDIMENSION_OBJ:
          case RDIMENSION_OBJ:
          case RBREAKDIMENSION_OBJ:
          case LBREAKDIMENSION_OBJ:
            //          case ABREAKDIMENSION_OBJ  :
          case ORDINATEDIMENSION_OBJ:
          case ARCDIMENSION_OBJ:
          {
            textParam->Init(TRUE);
            doc2D->ksGetObjParam(objRef, textParam, DIM_TEXT_PARAM);
            long bitFlag = textParam->bitFlag;
            if (bitFlag & _AUTONOMINAL)
            {
              textParam->SetBitFlagValue(_AUTONOMINAL, FALSE);
              doc2D->ksGetObjParam(objRef, dValue, DIM_VALUE);
              double value = dValue->value;
              sprintf(buff, "%g", value);
              char* p = strchr(buff, '.');
              if (p)
              {
                *p = ',';
                *(p + 3) = 0;
              }
              textItem->s = buff;

              dimArray->ksSetArrayItem(0, textItem);
              ksDynamicArrayPtr textArr(textParam->GetTextArr());
              if (bitFlag & _PREFIX)
              {
                if (textArr->ksGetArrayCount() > 1)
                  textArr->ksAddArrayItem(1, lineParam);
                else
                  textArr->ksAddArrayItem(-1, lineParam);
              }
              else
              {
                if (textArr->ksGetArrayCount() > 0)
                  textArr->ksAddArrayItem(0, lineParam);
                else
                  textArr->ksAddArrayItem(-1, lineParam);
              }
              doc2D->ksSetObjParam(objRef, textParam, DIM_TEXT_PARAM);
            }
          }
        }
      }

      objRef = itObj->ksMoveIterator("N");
    }
    itObj->ksDeleteIterator();
  }
}

//-----------------------------------------------------------------------------
// Активизировать вид и получить его параметры
// ---
void OnView(ksDocument2DPtr& doc2D, ksViewParamPtr& viewParam, ksLtVariantPtr& state, SArray<long>& vievs, long i)
{
  doc2D->ksOpenView(0);
  for (int j = 1, count = vievs.Count(); j < count; j++)
  {
    if (j == i)
      state->intVal = stACTIVE;
    doc2D->ksSetObjParam(vievs[j], state, VIEW_LAYER_STATE);
    if (j == i)
      state->intVal = stINVISIBLE;
  }
  doc2D->ksOpenView(doc2D->ksGetViewNumber(vievs[i]));
  doc2D->ksGetObjParam(vievs[i], viewParam, ALLPARAM);
}

#define KS_MAXDOUBLE (1.0E+300)
//-----------------------------------------------------------------------------
// Селектировать все видимые объекты документа
// ---
reference SelectGr(ksDocument2DPtr& doc2D, double x1, double y1, double x2, double y2)
{
  reference gr = doc2D->ksNewGroup(1);
  doc2D->ksEndGroup();
  doc2D->ksSelectGroup(gr, 3, x1, y1, x2, y2);
  return gr;
}


//-----------------------------------------------------------------------------
// Селектировать все видимые объекты документа
// ---
reference SelectAll(ksDocument2DPtr& doc2D)
{
  return SelectGr(doc2D, -KS_MAXDOUBLE, -KS_MAXDOUBLE, KS_MAXDOUBLE, KS_MAXDOUBLE);
}

CString CreateProjection(KompasObjectPtr& kompas, LPCTSTR m_PreviewFilename, LPCTSTR ProjectionName, double Scale, BOOL ConverToFrw)
{
  CString res;

  ksDocument2DPtr doc2D(kompas->Document2D());
  ksDocumentParamPtr docParam(kompas->GetParamStruct(ko_DocumentParam));
  docParam->Init();
  docParam->type = lt_DocSheetStandart;
  ksSheetParPtr sParam(docParam->GetLayoutParam());
  ksStandartSheetPtr stPar(sParam->GetSheetParam());
  stPar->format = 4;

  doc2D->ksCreateDocument(docParam);
  if (doc2D->reference)
  {
    ksAssociationViewParamPtr viewParam(kompas->GetParamStruct(ko_AssociationViewParam));
    viewParam->Init();
    viewParam->fileName = m_PreviewFilename;
    viewParam->projectionName = ProjectionName;
    ksViewParamPtr viewPar(viewParam->GetViewParam());
    viewPar->Init();
    viewPar->scale_ = Scale;
    long number = 1;
    viewParam->projBodies = true;
    viewParam->visibleLinesStyle = 1;
    viewParam->SetDimensionLayoutScaling(true);
    long view = doc2D->ksCreateSheetArbitraryView(viewParam, &number);
    doc2D->ksSetObjParam(view, viewParam, ASSOCIATION_VIEW_PARAM);

    // Удалим обозначение вида
    ksIteratorPtr it = kompas->GetIterator();
    if (it)
    {
      it->ksCreateIterator(TEXT_OBJ, 0);
      reference text = it->ksMoveIterator(_T("F"));
      it->ksDeleteIterator();
      if (text)
      {
        doc2D->ksDeleteObj(text);
      }
    }

    doc2D->ksDestroyObjects(view);
    if (ConverToFrw)
    {
      ksRectParamPtr rectParam(kompas->GetParamStruct(ko_RectParam));
      doc2D->ksGetObjGabaritRect(view, rectParam);
      ksMathPointParamPtr mpParam(rectParam->GetpBot());
      long gr = SelectAll(doc2D);
      if (doc2D->ksExistGroupObj(gr))
      {
        doc2D->ksMoveObj(gr, -mpParam->Getx(), -mpParam->Gety());
        doc2D->ksWriteGroupToClip(gr, FALSE);
        doc2D->ksClearGroup(gr, FALSE);
        doc2D->ksDeleteObj(gr);
        doc2D->ksCloseDocument();
        docParam->type = 3;
        ksDocument2DPtr docFrw2D(kompas->Document2D());
        docFrw2D->ksCreateDocument(docParam);
        long gr = docFrw2D->ksReadGroupFromClip();
        if (gr)
        {
          bool copy = ::fabs(Scale - 1.0) > 0.0001;
          //            reference gr1 = copy ? docFrw2D->ksCopyObj( gr, 0, 0, 0, 0, scaleL / scaleM, 0 ) : gr;
          reference gr1 = gr;
          if (copy)
          {
            ksDimTextParamPtr textParam(kompas->GetParamStruct(ko_DimText));

            //            SetLayer( kompas, doc2D, textParam, gr, 0, true ); 

            ksCopyObjectParamPtr param(kompas->GetParamStruct(ko_CopyObjectParam));
            param->Init();
            param->scale = Scale;
            param->objRef = gr;
            param->dimLineScale = true;

            gr1 = docFrw2D->ksCopyObjEx(param);
            docFrw2D->ksDeleteObj(gr);
          }
          docFrw2D->ksStoreTmpGroup(gr1);
          docFrw2D->ksClearGroup(gr1, false);
          docFrw2D->ksDeleteObj(gr1);

        }
        //TCHAR fileName[260];
        //_tcscpy( fileName, m_PreviewFilename );
        //fileName[_tcslen(fileName)-4] = 0;
        //_tcscat(fileName, _T("_эскиз.frw"));
        res = GetTmpFileName(kompas, m_PreviewFilename, _T("_эскиз.frw")); // #81108
#ifdef FULL_DEBUG
        PutLogMsg("Сохраняем и закрываем фрагмент.");
#endif
        docFrw2D->ksSaveDocument((LPCTSTR)res);
        docFrw2D->ksCloseDocument();
        kompas->ksResultNULL();
#ifdef FULL_DEBUG
        PutLogMsg("Закрыли фрагмент.");
#endif
        //        res = fileName; 
      }
    }
    else
    {
#ifdef FULL_DEBUG
      PutLogMsg("Сохраняем и закрываем чертеж.");
#endif
      //      TCHAR fileName[260];
      //      _tcscpy( fileName, m_PreviewFilename );
      //      fileName[_tcslen(fileName)-4] = 0;
      //      _tcscat(fileName, _T("_эскиз.cdw"));
      res = GetTmpFileName(kompas, m_PreviewFilename, _T("_эскиз.cdw")); // #81108
      doc2D->ksSaveDocument((LPCTSTR)res);
      doc2D->ksCloseDocument();
      kompas->ksResultNULL();

      //      res = fileName; 
    }
  }
  return res;
}

//-----------------------------------------------------------------------------
// Список объектов
// ---
void FillObjects(KompasObjectPtr& kompas, SArray<long>& objects, long type, reference parent = 0)
{
  ksIteratorPtr itObj = kompas->GetIterator();
  if (itObj)
  {
    itObj->ksCreateIterator(type, parent);
    reference objRef = itObj->ksMoveIterator(_T("F"));
    while (objRef)
    {
      objects.Add(objRef);
      objRef = itObj->ksMoveIterator(_T("N"));
    }
    itObj->ksDeleteIterator();
  }
}


//-----------------------------------------------------------------------------
// Список объектов
// ---
void FillObjects(ksDocument2DPtr& doc2D, SArray<long>& allObj, SArray<long>& objects, long type)
{
  reference nextObj;
  for (int i = 0, count = allObj.Count(); i < count; i++)
  {
    nextObj = allObj[i];
    if (doc2D->ksGetObjParam(nextObj, NULL, ALLPARAM) == type)
      objects.Add(nextObj);
  }
}



//-----------------------------------------------------------------------------
// Список видов
// ---
void FillViews(KompasObjectPtr& kompas, SArray<long>& vievs)
{
  if (kompas->ksGetDocumentType(0) == lt_DocFragment)
    vievs.Add(0);
  else
    FillObjects(kompas, vievs, VIEW_OBJ);
}

CString ConvertCdwToFrw(KompasObjectPtr& kompas, _bstr_t filename, bool clearLayout)
{
  long type = kompas->ksGetDocumentTypeByName(filename);
  if (type == lt_DocSheetStandart || type == lt_DocFragment || type == lt_DocSheetUser)
  {
    CString tmpFileName;
    if (type == lt_DocFragment)
      tmpFileName = GetTmpFileName(kompas, (LPCTSTR)filename, _T("tmp.frw")); // #81108
    else
      tmpFileName = GetTmpFileName(kompas, (LPCTSTR)filename, _T("tmp.cdw")); // #81108
    BOOL copy = CopyFile(filename, tmpFileName, FALSE);

    ksDocument2DPtr doc2D(kompas->Document2D());
    if (copy && doc2D->ksOpenDocument((LPCTSTR)tmpFileName, FALSE))
    {
      IApplicationPtr kompasApp(kompas->ksGetApplication7());
      IKompasDocument2DPtr doc(kompasApp->ActiveDocument);
      if (clearLayout)
      {
        if (doc)
        {
          ILayoutSheetsPtr layouts(doc->LayoutSheets);
          if (layouts)
          {
            ILayoutSheetPtr layout;
            for (long i = layouts->Count - 1; i > 0; i--)
            {
              layout = layouts->Item[i];
              if (layout)
                layout->Delete();
            }
            layout = layouts->Item[0];
            if (layout)
            {
              layout->LayoutLibraryFileName = _bstr_t(_T(""));
              layout->LayoutStyleNumber = 0;
              layout->Update();
            }
          }
        }
        reference techTreb = doc2D->ksGetReferenceDocumentPart(1);
        if (techTreb)
          doc2D->ksDeleteObj(techTreb);

        doc2D->ksSaveDocument(_bstr_t());
        doc2D->ksCloseDocument();
        kompas->ksResultNULL();
        return ((LPCTSTR)tmpFileName);
      }
      else
      {
        ksDocument2DPtr docFrw(kompas->Document2D());
        ksDocumentParamPtr docParam(kompas->GetParamStruct(ko_DocumentParam));
        if ((bool)docFrw && (bool)doc2D && (bool)docParam)
        {
          SArray<long> views;
          FillViews(kompas, views);
          docParam->type = type == lt_DocFragment ? lt_DocSheetUser : lt_DocFragment;
          docParam->regime = 1;
          docFrw->ksCreateDocument(docParam);
          reference gr, gr1 = 0;
          ksViewParamPtr viewParam(kompas->GetParamStruct(ko_ViewParam));
          ksDimTextParamPtr textParam(kompas->GetParamStruct(ko_DimText));
          ksLtVariantPtr state(kompas->GetParamStruct(ko_LtVariant));
          state->intVal = stINVISIBLE;
          for (int i = views.Count() - 1, j = views.Count() - 1; i >= 0; i--)
          {
            reference nextView = views[i];

            if (type == lt_DocFragment || doc2D->ksGetViewObjCount(nextView) > 0)
            {
              if (type != lt_DocFragment)
                OnView(doc2D, viewParam, state, views, i);

              IViewPtr activeView(doc->ViewsAndLayersManager->Views->ViewByNumber[doc2D->ksGetViewNumber(nextView)]);
              if (activeView && activeView->ViewType > vt_Normal)
                doc2D->ksDestroyObjects(nextView);
              IBreakViewParamPtr breakParam(activeView);
              if (breakParam && breakParam->BreaksCount > 0 && breakParam->BreaksVisible)
                doc2D->ksDestroyObjects(nextView);

              gr = SelectAll(doc2D);
              if (gr && doc2D->ksExistGroupObj(gr))
              {
                doc2D->ksWriteGroupToClip(gr, TRUE);
                docFrw->ksLayer(j);
                gr = docFrw->ksReadGroupFromClip();
                gr1 = docFrw->ksCopyObj(gr, 0, 0, viewParam->x, viewParam->y, viewParam->scale_ /*0*/, viewParam->angle);
                //                if ( type != lt_DocFragment )
                //                  SetLayer( kompas, docFrw, textParam, gr1, j, fabs( viewParam->scale_ - 1.0 ) > 0.0001 /*FALSE*/ );
                docFrw->ksStoreTmpGroup(gr1);
                docFrw->ksDeleteObj(gr);
                docFrw->ksClearGroup(gr1, TRUE);
                docFrw->ksDeleteObj(gr1);
                j--;
              }
            }
          }
          docFrw->ksLayer(0);
          if (type != lt_DocFragment)
          {
            ksSpecRoughParamPtr rParam(kompas->GetParamStruct(ko_SpecRoughParam));
            reference rough = doc2D->ksGetReferenceDocumentPart(2); // Неуазанная шероховатость
            if (rough && (bool)rParam)
            {
              doc2D->ksGetObjParam(rough, rParam, ALLPARAM);        // Получаем параметры

              int     roughType = rParam->sign; // Тип значка
              CString roughStr((LPCTSTR)rParam->s);      // Строка
              int     roughT = rParam->t;    // Тип
              //              CreateLibRough( kompas, doc2D, docFrw, rough, -1, roughType, roughStr, roughT );
            }
          }

          CString newFileName;
          if (type == lt_DocFragment)
            newFileName = GetTmpFileName(kompas, (LPCTSTR)filename, _T(".cdw")); // #81108
          else
            newFileName = GetTmpFileName(kompas, (LPCTSTR)filename, _T(".frw")); // #81108

          docFrw->ksSaveDocument((LPCTSTR)newFileName);
          docFrw->ksCloseDocument();

          doc2D->ksCloseDocument();
          kompas->ksResultNULL();
          return ((LPCTSTR)newFileName);
        }
      }
    }
  }
  return LPCTSTR();
}


afx_msg void CTestView::OnFileNew()
{
  KompasObjectPtr pKompas = m_KompasCtrl->GetKompasObject();
  if (pKompas)
  {
    CString strFilter = _T("Файлы КОМПАС(*.cdw)|*.cdw");
    CString filename = (LPCTSTR)pKompas->ksChoiceFile(_T("cdw"), LPCTSTR(strFilter), 1);

    // CString res = CreateProjection( pKompas, _T("D:\\1.m3d"), _T("#Спереди"), 10, true ); 
    CString res = ConvertCdwToFrw(pKompas, (LPCTSTR)filename, false);
    if (!res.IsEmpty())
      m_KompasCtrl->AddDocument((LPCTSTR)res);
  }
}

//-----------------------------------------------------------------------------
// Селектировать все грани
// ---
void EditDocument(KompasObjectPtr& kompas, _bstr_t filename)
{
  HWND wnd = (HWND)LongToHandle(kompas->ksGetHWindow());
  if (kompas->ksGetSystemControlStartResult() == scsSTOPPED_FOR_START_THIS_LIB)
  {
    BOOL bVis = kompas->Visible;
    if (!bVis)
      kompas->Visible = TRUE; // Нужно чтобы фокус перешел в Компас иначе глюки на открытии документа

    wnd = (HWND)LongToHandle(kompas->ksGetHWindow());
    ::SetForegroundWindow(wnd); // делаем окно Компаса верхним чтобы окно выбора файла было выше окна Вертикали
    ::AfxMessageBox(_T("Документ уже редактируется в Компас.\n Требуется завершить редактирование."), MB_OK);

    if (!bVis)
      kompas->Visible = FALSE; // Нужно чтобы фокус перешел в Компас иначе глюки на открытии документа

    return;
  }

  if (filename.length() == 0)
    return;

  int type = kompas->ksGetDocumentTypeByName(filename);
  if (!type)
    return;

  BOOL bVis = kompas->Visible;




  IApplicationPtr appi7(kompas->ksGetApplication7());
  if (appi7)
    appi7->HideMessage = ksShowMessage;

  if (!bVis)
    kompas->Visible = TRUE;

  kompas->Visible = FALSE;


  ksDocument2DPtr doc2d;
  ksDocument3DPtr doc3d;
  ksSpcDocumentPtr docspc;
  IDispatchPtr doc;
  if (type == lt_DocPart3D || type == lt_DocAssemble3D || type == lt_DocTechnologyAssemble3D) // 3D модель
  {
    doc3d = kompas->Document3D();
    doc3d->Open(filename, FALSE);
    doc = doc3d;
  }
  else if (type == lt_DocSpc || type == lt_DocSpcUser) // 3D модель
  {
    docspc = kompas->SpcDocument();
    docspc->ksOpenDocument(filename, false);
    doc = docspc;
  }
  else
  {
    doc2d = kompas->Document2D();
    doc2d->ksOpenDocument(LPCTSTR(filename), 0);
    doc = doc2d;
  }

  kompas->Visible = TRUE;

  //  LockPumpMessages( 0 );
  wnd = (HWND)LongToHandle(kompas->ksGetHWindow());

  ::SetForegroundWindow(wnd); // делаем окно Компаса верхним чтобы окно выбора файла было выше окна Вертикали
  ::BringWindowToTop(wnd);


  DocumentEvent* event = new DocumentEvent(doc);
  event->SetKompas(kompas);
  event->Advise();

  // scsSTOPPED_FOR_MENU_COMMAND    (  1 ) - выполнена команда меню "Остановить работу библиотеки"
  // scsSTOPPED_FOR_SYSTEM_STOP      (  0 ) - закрытие Компаса.
  // scsSTOPPED_FOR_ITSELF          ( -1 ) - вызов ф-ции ksSystemControlStop из-под библиотеки.
  // scsSTOPPED_FOR_START_THIS_LIB  ( -2 ) - принудительный останов при запуске той же библиотеки.
  // scsSTOPPED_FOR_START_ANOTHER_LIB ( -3 ) - принудительный остнов при запуске другой библиотеки.
  long res = 0;

  //  do 
  //  { 
  res = kompas->ksSystemControlStart(_T("Вернуться в Вертикаль"));

  //    if ( res == scsSTOPPED_FOR_START_THIS_LIB )
  //      ::MessageBox(NULL, _T("Еще одна библиотека"), _T(""), MB_OK);

  //  } while( res != scsSTOPPED_FOR_SYSTEM_STOP    && res != scsSTOPPED_FOR_ITSELF &&
  //         res != scsSTOPPED_FOR_START_THIS_LIB && res != scsSTOPPED_FOR_MENU_COMMAND );

  event->Disconnect();


  //        delete event;
  if (doc3d)
    doc3d->close();
  else
    if (doc2d)
      doc2d->ksCloseDocument();
    else
      if (docspc)
        docspc->ksCloseDocument();

  kompas->ksPumpWaitingMessages();

  if (!bVis)
  {
    kompas->Visible = bVis;

    if (appi7)
      appi7->HideMessage = ksHideMessageNo;
  }
  //  kompas->ksPumpWaitingMessages();
  kompas->ksResultNULL();
}

afx_msg void CTestView::OnFileReload()
{
  KompasObjectPtr pKompas = m_KompasCtrl->GetKompasObject();
  if (pKompas)
  {
    _bstr_t fileName = m_KompasCtrl->DocumenFileName;
    m_KompasCtrl->RemoveDocument(fileName);
    EditDocument(pKompas, fileName);
    //    pKompas->Visible = VARIANT_TRUE;
    //
    //    IApplicationPtr api7( pKompas->ksGetApplication7() );
    //    if ( api7 )
    //    {
    //      api7->HideMessage = ksShowMessage;
    //
    //      IKompasDocumentPtr doc( api7->Documents->Open( fileName, true, false ) );
    //      if ( doc )
    //      { 
    //        pKompas->ksSystemControlStart( _T("Вернуться в Вертикаль") );
    //        doc->Close( kdPromptToSaveChanges );
    //      }
    //      api7->HideMessage = ksHideMessageNo;
    //
    //    }

        // Sleep( 3000 );
    m_KompasCtrl->AddDocument(fileName);
  }
}



void CTestView::OnSize(UINT nType, int cx, int cy)
{
  CView::OnSize(nType, cx, cy);

  if (::IsWindow(m_KompasCtrl.m_hWnd))
    m_KompasCtrl.MoveWindow(0, 0, cx, cy, TRUE);
}

afx_msg void CTestView::OnDestroy()
{
  KompasObjectPtr pKompas = m_KompasCtrl->GetKompasObject();
  if (pKompas)
  {
    m_KompasCtrl->CloseAll();
  }
  CView::OnDestroy();
}

void CTestView::Command3D(ksDocument3DPtr pDoc)
{
  ksPartPtr part = pDoc->GetPart(pTop_Part);
  ksEntityPtr entitySketch = part->NewEntity(o3d_sketch);
  ksSketchDefinitionPtr sketchDef = entitySketch->GetDefinition();

  ksEntityPtr basePlane = part->GetDefaultEntity(o3d_planeXOY);
  sketchDef->SetPlane(basePlane);
  sketchDef->angle = 45;
  entitySketch->Create();

  ksDocument2DPtr sketchEdit = sketchDef->BeginEdit();
  sketchEdit->ksLineSeg(50, 50, -50, 50, 1);
  sketchEdit->ksLineSeg(50, -50, -50, -50, 1);
  sketchEdit->ksLineSeg(50, -50, 50, 50, 1);
  sketchEdit->ksLineSeg(-50, -50, -50, 50, 1);
  sketchDef->EndEdit();

  ksEntityPtr entityExtr = part->NewEntity(o3d_bossExtrusion);
  ksBossExtrusionDefinitionPtr extrusionDef = entityExtr->GetDefinition();
  extrusionDef->directionType = dtNormal;
  extrusionDef->SetSideParam(TRUE, etBlind, 200, 0, FALSE);
  extrusionDef->SetThinParam(TRUE, dtBoth, 10, 10);
  extrusionDef->SetSketch(entitySketch);
  entityExtr->Create();

  m_KompasCtrl->ZoomEntireDocument();
  // pDoc->UserSelectEntity( NULL, _bstr_t(), _bstr_t(), 0, NULL );
  pDoc->Save();
}

void CTestView::Command2D(ksDocument2DPtr pDoc2D)
{
  pDoc2D->ksLineSeg(10, 10, 100, 10, 1);
  double x = 0, y = 0;
  bool res = pDoc2D->ksCursor(nullptr, &x, &y, nullptr);
  if (res)
  {

  }
}

void CTestView::OnAppAbout()
{
  KompasObjectPtr pKompas = m_KompasCtrl->GetKompasObject();
  ksDocument3DPtr pDoc = pKompas->ActiveDocument3D();
  if (pDoc)
  {
    if (!pKompas->ksIsModule3DActive())
      pKompas->ksModule3D(VARIANT_TRUE);
    Command3D(pDoc);
  }
  else
  {
    ksDocument2DPtr pDoc2D = pKompas->ActiveDocument2D();
    if (pDoc2D)
      Command2D(pDoc2D);
  }
}
