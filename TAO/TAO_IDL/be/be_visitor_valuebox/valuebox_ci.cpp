//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    valuebox_ci.cpp
//
// = DESCRIPTION
//    Visitor generating code for valueboxes in the client inline file
//
// = AUTHOR
//    Gary Maxey
//
// ============================================================================

ACE_RCSID (be_visitor_valuebox, 
           valuebox_ci, 
           "$Id: valuebox_ci.cpp Exp")

be_visitor_valuebox_ci::be_visitor_valuebox_ci (be_visitor_context *ctx)
  : be_visitor_valuebox (ctx)
{
}

be_visitor_valuebox_ci::~be_visitor_valuebox_ci (void)
{
}

int
be_visitor_valuebox_ci::visit_valuebox (be_valuebox *node)
{
  // Nothing to do if we are imported or code is already generated.
  if (node->imported () || node->cli_inline_gen ())
    {
      return 0;
    }

  TAO_OutStream *os = this->ctx_->stream ();

  this->ctx_->node (node); // save the node

  be_type *bt = be_type::narrow_from_decl (node->boxed_type ()); 

  // Emit the type specific elements.  The visit_* methods in this
  // module do that work.
  if (!bt || (bt->accept (this) == -1))
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         " (%N:%l) be_visitor_valuebox_ci::visit_valuebox - "
                         "type-specific valuebox code generation failed\n"),
                        -1);
    }

  *os << be_nl << be_nl << "// TAO_IDL - Generated from" << be_nl
      << "// " << __FILE__ << ":" << __LINE__ << be_nl;

  *os << "ACE_INLINE const char* " << be_nl
      << node->name () << "::_tao_obv_static_repository_id ()" << be_nl
      << "{" << be_idt_nl
      << "return \"" << node->repoID () << "\";" << be_uidt_nl
      << "}" << be_nl << be_nl;

  // _tao_unmarshal_v method.  Generated because ValueBase interface
  // requires it.  But there is nothing for it to do in the valuebox
  // case.
  *os << "ACE_INLINE CORBA::Boolean " << be_nl
      << node->name ()
      << "::_tao_unmarshal_v (TAO_InputCDR & strm)" << be_nl
      << "{" << be_idt_nl  
      << "return 1;" << be_uidt_nl 
      << "}" << be_nl << be_nl;

  // Indicate that code is already generated for this node.
  node->cli_inline_gen (I_TRUE);

  return 0;
}

int
be_visitor_valuebox_ci::visit_array (be_array *node)
{
		
  TAO_OutStream *os = this->ctx_->stream ();
  
  // Retrieve the node being visited by this be_visitor_valuebox_ch.
  be_decl * vb_node = this->ctx_->node ();

  *os << be_nl << be_nl << "// TAO_IDL - Generated from" << be_nl
      << "// " << __FILE__ << ":" << __LINE__ << be_nl << be_nl;

  // Public default constructor
  *os << "ACE_INLINE" << be_nl
      << vb_node->name () << "::" << vb_node->local_name () << " (void)"
      << be_nl << "{" << be_idt_nl
      << "this->_pd_value = " << node->full_name () << "_alloc ();"
      << be_uidt_nl << "}" << be_nl << be_nl;
  
  // Protected destructor
  *os << "ACE_INLINE" << be_nl
      << vb_node->name () << "::~" << vb_node->local_name () << " (void)"
      << be_nl << "{" << be_nl
      << "}" << be_nl << be_nl;

  // Public constructor that takes a const array argument
  *os << "ACE_INLINE" << be_nl
      << vb_node->name () << "::" << vb_node->local_name () << " (const "
      << node->full_name () << " val)" << be_nl
      << "{" << be_idt_nl
      << "this->_pd_value = " << node->full_name () << "_dup (val);"
      << be_uidt_nl
      << "}" << be_nl << be_nl;

  // Public copy constructor
  *os << "ACE_INLINE" << be_nl
      << vb_node->name () << "::" << vb_node->local_name () << " (const "
      << vb_node->local_name () << "& val)" << be_nl
      << "{" << be_idt_nl
      << "this->_pd_value = " << node->full_name ()
      << "_dup (val._pd_value.in ());" << be_uidt_nl
      << "}" << be_nl << be_nl;

  // Public assignment operator that takes a const array argument
  *os << "ACE_INLINE " << vb_node->name () << " &" << be_nl
      << vb_node->name () << "::operator= (const "
      << node->full_name () << " val)" << be_nl
      << "{" << be_idt_nl
      << "this->_pd_value = " << node->full_name ()
      << "_dup (val);" << be_nl
      << "return *this;" << be_uidt_nl
      << "}" << be_nl << be_nl;

  // Public accessor and modifier methods        
  *os << "ACE_INLINE const " << node->full_name () << "_slice*" << be_nl 
      << vb_node->name () << "::_value (void) const" << be_nl
      << "{" << be_idt_nl
      << "return this->_pd_value.in ();" << be_uidt_nl
      << "}" << be_nl << be_nl;
 
  *os << "ACE_INLINE " << node->full_name () << "_slice*" << be_nl 
      << vb_node->name () << "::_value (void)" << be_nl
      << "{" << be_idt_nl
      << "return this->_pd_value.inout ();" << be_uidt_nl
      << "}" << be_nl << be_nl;

  *os << "ACE_INLINE void" << be_nl 
      << vb_node->name () << "::_value (const " << node->full_name ()
      << " val)" << be_nl
      << "{" << be_idt_nl
      << "this->_pd_value = " << node->full_name () << "_dup (val);"
      << be_uidt_nl
      << "}" << be_nl << be_nl;

  // Overloaded subscript operators
  *os << "ACE_INLINE const " << node->full_name () << "_slice &" << be_nl
      << vb_node->name () << "::operator[] (CORBA::ULong index) const"
      << be_nl
      << "{" << be_idt_nl
      << "return this->_pd_value[index];" << be_uidt_nl
      << "}" << be_nl << be_nl;

  *os << "ACE_INLINE "<< node->full_name () << "_slice &" << be_nl
      << vb_node->name () << "::operator[] (CORBA::ULong index)" << be_nl
      << "{" << be_idt_nl
      << "return this->_pd_value[index];" << be_uidt_nl
      << "}" << be_nl << be_nl;

  // Explicit conversion functions
  *os << "ACE_INLINE const " << node->full_name () << "_slice *" << be_nl 
      << vb_node->name () << "::_boxed_in (void) const" << be_nl
      << "{" << be_idt_nl
      << "return this->_pd_value.in ();" << be_uidt_nl
      << "}" << be_nl << be_nl;

  *os << "ACE_INLINE " << node->full_name () << "_slice *" << be_nl 
      << vb_node->name () << "::_boxed_inout (void)" << be_nl
      << "{" << be_idt_nl
      << "return this->_pd_value.inout ();" << be_uidt_nl
      << "}" << be_nl << be_nl;

  *os << "ACE_INLINE " << node->full_name () << "_slice *" << be_nl 
      << vb_node->name () << "::_boxed_out (void)" << be_nl
      << "{" << be_idt_nl
      << "return this->_pd_value.inout ();" << be_uidt_nl
      << "}" << be_nl << be_nl;

  // _tao_marshal_v method
  *os << "ACE_INLINE CORBA::Boolean " << be_nl
      << vb_node->name ()
      << "::_tao_marshal_v (TAO_OutputCDR & strm) const" << be_nl
      << "{" << be_idt_nl
      << node->name () << "_forany temp (this->_pd_value);" << be_nl
      << "return (strm << temp);" << be_uidt_nl 
      << "}" << be_nl << be_nl;

  return 0;
}

int
be_visitor_valuebox_ci::visit_enum (be_enum *node)
{
  return this->emit_for_predef_enum (node, "", false,
                                     "this->_pd_value");
}

int
be_visitor_valuebox_ci::visit_interface (be_interface *node)
{
  return this->emit_for_predef_enum (node, "_ptr", false,
                                     "this->_pd_value");
}

int
be_visitor_valuebox_ci::visit_predefined_type (be_predefined_type *node)
{
  char *marshal_arg;
  bool is_any = false;

  switch (node->pt())
    {
    case AST_PredefinedType::PT_boolean:
      marshal_arg = "CORBA::Any::from_boolean (this->_pd_value)";
      break;

    case AST_PredefinedType::PT_char:
      marshal_arg = "CORBA::Any::from_char (this->_pd_value)";
      break;

    case AST_PredefinedType::PT_wchar:
      marshal_arg = "CORBA::Any::from_wchar (this->_pd_value)";
      break;

    case AST_PredefinedType::PT_octet:
      marshal_arg = "CORBA::Any::from_octet (this->_pd_value)";
      break;

    case AST_PredefinedType::PT_any:
      marshal_arg = "this->_pd_value.in ()";
      is_any = true;
      break;

    default:
      marshal_arg = "this->_pd_value";
    }
  return this->emit_for_predef_enum (node, "", is_any, marshal_arg);
}

int
be_visitor_valuebox_ci::visit_sequence (be_sequence *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  
  // Retrieve the node being visited by this be_visitor_valuebox_ch.
  be_decl * vb_node = this->ctx_->node ();
 
  *os << be_nl << be_nl << "// TAO_IDL - Generated from" << be_nl
      << "// " << __FILE__ << ":" << __LINE__ << be_nl << be_nl;

  this->emit_default_constructor_alloc (node);
  this->emit_destructor ();
  this->emit_constructor_one_arg_alloc (node);
  this->emit_copy_constructor_alloc (node);
  this->emit_assignment_alloc (node);
  this->emit_accessor_modifier (node);
  this->emit_boxed_access(node, "*");

  // Generate maximum() accessor
  *os << "ACE_INLINE CORBA::ULong " << be_nl
      << vb_node->name () << "::maximum (void) const" << be_nl
      << "{" << be_idt_nl
      << "return this->_pd_value->maximum ();" << be_uidt_nl
      << "}" << be_nl << be_nl;

  // Generate length() accessor
  *os << "ACE_INLINE CORBA::ULong " << be_nl
      << vb_node->name () << "::length (void) const" << be_nl
      << "{" << be_idt_nl
      << "return this->_pd_value->length ();" << be_uidt_nl
      << "}" << be_nl << be_nl;

  // Generate length() setter
  *os << "ACE_INLINE void " << be_nl
      << vb_node->name () << "::length (CORBA::ULong length)" << be_nl
      << "{" << be_idt_nl
      << "this->_pd_value->length (length);" << be_uidt_nl
      << "}" << be_nl << be_nl;

  // _tao_marshal_v method
  *os << "ACE_INLINE CORBA::Boolean " << be_nl
      << vb_node->name ()
      << "::_tao_marshal_v (TAO_OutputCDR & strm) const" << be_nl
      << "{" << be_idt_nl  
      << "return (strm << this->_pd_value.in ());" << be_uidt_nl 
      << "}" << be_nl << be_nl;
   
  return 0;
}

int
be_visitor_valuebox_ci::visit_string (be_string *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  
  char *string_type;
  char *char_type;
  if (node->node_type () == AST_Decl::NT_string)
    {
      string_type = "String";
      char_type = "char";
    }
  else if (node->node_type () == AST_Decl::NT_wstring)
    {
      string_type = "WString";
      char_type = "CORBA::WChar";
    }
  else
    {
      ACE_ERROR ((LM_ERROR,
                  "(%N:%l) be_visitor_valuebox_ci::visit_string -"
                  "unexpected string node type=%d\n", node->node_type ()));
      return -1;
    }

  // Retrieve the node being visited by this be_visitor_valuebox_ch.
  be_decl * vb_node = this->ctx_->node ();
  
  *os << be_nl << be_nl << "// TAO_IDL - Generated from" << be_nl
      << "// " << __FILE__ << ":" << __LINE__ << be_nl << be_nl;

  this->emit_default_constructor ();
  this->emit_destructor ();
  this->emit_constructor_one_arg (node, "");
  this->emit_copy_constructor ();
  this->emit_assignment (node, "");

  // Public constructor with one const argument of underlying type
  *os << "ACE_INLINE " << be_nl
      << vb_node->name () << "::" << vb_node->local_name () << " (const "
      << node->full_name () << " val)" << be_nl
      << "{" << be_idt_nl
      << "this->_pd_value = val;" << be_uidt_nl
      << "}" << be_nl << be_nl;


  // Public constructor with one argument of type const CORBA::String_var&
  *os << "ACE_INLINE" << be_nl
      << vb_node->name () << "::" << vb_node->local_name ()
      << " (const CORBA::" << string_type << "_var& var)" << be_nl
      << "{" << be_idt_nl
      << "this->_pd_value = var;" << be_uidt_nl
      << "}" << be_nl << be_nl;

  // Public assignment operator with one argument of type const char *
  *os << "ACE_INLINE " << vb_node->name () << " &" << be_nl
      << vb_node->name () << "::operator= (const "
      << node->full_name () << " val)" << be_nl
      << "{" << be_idt_nl
      << "this->_pd_value = val;" << be_nl
      << "return *this;" << be_uidt_nl
      << "}" << be_nl << be_nl;

  // Public assignment operator with one argument of type
  // const CORBA::String_var&
  *os << "ACE_INLINE " << vb_node->name () << " &" << be_nl
      << vb_node->name () << "::operator= (const CORBA::"
      << string_type << "_var& var)"
      << be_nl
      << "{" << be_idt_nl
      << "this->_pd_value = var;" << be_nl
      << "return *this;" << be_uidt_nl
      << "}" << be_nl << be_nl;

  // Accessor function takes no arguments and returns a const char *
  *os << "ACE_INLINE const " << node->full_name () << be_nl 
      << vb_node->name () << "::_value (void) const" << be_nl
      << "{" << be_idt_nl
      << "return this->_pd_value.in ();" << be_uidt_nl
      << "}" << be_nl << be_nl;

  // Modifier function with one argument of type char *
  *os << "ACE_INLINE void" << be_nl 
      << vb_node->name () << "::_value (" 
      << node->full_name () << " val)" << be_nl
      << "{" << be_idt_nl
      << "this->_pd_value = val;" << be_uidt_nl
      << "}" << be_nl << be_nl;

  // Modifier function with one argument of type const char *
  *os << "ACE_INLINE void" << be_nl 
      << vb_node->name () << "::_value (const " 
      << node->full_name () << " val)" << be_nl
      << "{" << be_idt_nl
      << "this->_pd_value = val;" << be_uidt_nl
      << "}" << be_nl << be_nl;

  // Modifier function with one argument of type const CORBA::String_var&
  *os << "ACE_INLINE void" << be_nl 
      << vb_node->name () << "::_value (const CORBA::" << string_type
      << "_var& var)" << be_nl
      << "{" << be_idt_nl
      << "this->_pd_value = var;" << be_uidt_nl
      << "}" << be_nl << be_nl;

  // Access to the boxed value for method signatures
  *os << "ACE_INLINE const " << node->full_name () << be_nl 
      << vb_node->name () << "::_boxed_in (void) const" << be_nl
      << "{" << be_idt_nl
      << "return this->_pd_value.in ();" << be_uidt_nl
      << "}" << be_nl << be_nl;

  *os << "ACE_INLINE " << node->full_name () << "&" << be_nl 
      << vb_node->name () << "::_boxed_inout (void)" << be_nl
      << "{" << be_idt_nl
      << "return this->_pd_value;" << be_uidt_nl
      << "}" << be_nl << be_nl;

  *os << "ACE_INLINE " << node->full_name () << "&" << be_nl 
      << vb_node->name () << "::_boxed_out (void)" << be_nl
      << "{" << be_idt_nl
      << "return this->_pd_value;" << be_uidt_nl
      << "}" << be_nl << be_nl;

  // Overloaded subscript operators
  *os << "ACE_INLINE " << char_type << " &" << be_nl
      << vb_node->name () << "::operator[] (CORBA::ULong slot)" << be_nl
      << "{" << be_idt_nl
      << "return this->_pd_value[slot];" << be_uidt_nl
      << "}" << be_nl << be_nl;

  *os << "ACE_INLINE " << char_type << be_nl
      << vb_node->name () << "::operator[] (CORBA::ULong slot) const" << be_nl
      << "{" << be_idt_nl
      << "return this->_pd_value[slot];" << be_uidt_nl
      << "}" << be_nl << be_nl;


  // _tao_marshal_v method
  *os << "ACE_INLINE CORBA::Boolean " << be_nl
      << vb_node->name ()
      << "::_tao_marshal_v (TAO_OutputCDR & strm) const" << be_nl
      << "{" << be_idt_nl  
      << "return (strm << this->_pd_value);" << be_uidt_nl 
      << "}" << be_nl << be_nl;

  return 0;
}

int
be_visitor_valuebox_ci::visit_structure (be_structure *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  
  // Retrieve the node being visited by this be_visitor_valuebox_ch.
  be_decl * vb_node = this->ctx_->node ();
  
  *os << be_nl << be_nl << "// TAO_IDL - Generated from" << be_nl
      << "// " << __FILE__ << ":" << __LINE__ << be_nl << be_nl;

  this->emit_default_constructor_alloc (node);
  this->emit_destructor ();
  this->emit_constructor_one_arg_alloc (node);
  this->emit_copy_constructor_alloc (node);
  this->emit_assignment_alloc (node);
  this->emit_accessor_modifier (node);
  // Access to the boxed value for method signatures
  if (node->size_type() == AST_Type::FIXED)
    {
      this->emit_boxed_access (node, "");
    }
  else
    {
      this->emit_boxed_access (node, "*");
    }

  // Now generate the accessor and modifier functions for each struct
  // member.  These functions have the same signatures as
  // acessor and modifier functions for union members.
  AST_Decl *d;
  be_field *field;
  be_visitor_context ctx (*this->ctx_);
  ctx.scope (vb_node);
  for (UTL_ScopeActiveIterator si (node, UTL_Scope::IK_decls);
       !si.is_done ();
        si.next ())
    {
      d = si.item ();

      if (d == 0 || (field = be_field::narrow_from_decl (d)) == 0)
        {
          ACE_ERROR ((LM_ERROR,
                      "(%N:%l) be_visitor_valuebox_cs::visit_structure -"
                      "bad node in this scope\n"));
          break;
        }

      // Create a visitor and use that to process the field type.
      be_visitor_valuebox_field_ci visitor (&ctx);
      ctx.node (field);

      if (visitor.visit_field (field) == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_valuebox_cs::visit_structure - "
                             "visit_field failed\n"
                         ), -1);
        }
    }

  // _tao_marshal_v method
  *os << "ACE_INLINE CORBA::Boolean " << be_nl
      << vb_node->name ()
      << "::_tao_marshal_v (TAO_OutputCDR & strm) const" << be_nl
      << "{" << be_idt_nl  
      << "return (strm << this->_pd_value.in ());" << be_uidt_nl 
      << "}" << be_nl << be_nl;

  return 0;
}

int
be_visitor_valuebox_ci::visit_typedef (be_typedef *node)
{
  // Make a decision based on the primitive base type.
  be_type *bt = node->primitive_base_type ();

  if (!bt || (bt->accept (this) == -1))
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_valuebox_ci::"
                         "visit_typedef - "
                         "Bad primitive type\n"),
                        -1);
    }

  return 0;
}

int
be_visitor_valuebox_ci::visit_union (be_union *node)
{
  TAO_OutStream *os = this->ctx_->stream ();

  // Retrieve the node being visited by this be_visitor_valuebox_ci.
  be_decl * vb_node = this->ctx_->node ();
 
  *os << be_nl << be_nl << "// TAO_IDL - Generated from" << be_nl
      << "// " << __FILE__ << ":" << __LINE__ << be_nl << be_nl;

  this->emit_default_constructor_alloc (node);
  this->emit_destructor ();
  this->emit_constructor_one_arg_alloc (node);
  this->emit_copy_constructor_alloc (node);
  this->emit_assignment_alloc (node);
  this->emit_accessor_modifier (node);
  if (node->size_type() == AST_Type::FIXED)
    {
      this->emit_boxed_access (node, "");
    }
  else
    {
      this->emit_boxed_access (node, "*");
    }

  // Now generate the accessor and modifier functions for each union
  // member.
  AST_Decl *d;
  be_union_branch *member;
  be_visitor_context ctx (*this->ctx_);
  ctx.scope (vb_node);
  for (UTL_ScopeActiveIterator si (node, UTL_Scope::IK_decls);
       !si.is_done ();
        si.next ())
    {
      d = si.item ();

      if (d == 0 || (member = be_union_branch::narrow_from_decl (d)) == 0)
        {
          ACE_ERROR ((LM_ERROR,
                      "(%N:%l) be_visitor_valuebox_ci::visit_union -"
                      "bad node in this scope\n"));
          break;
        }

      // Create a visitor and use that to process the union member type.
      be_visitor_valuebox_union_member_ci visitor (&ctx);
      ctx.node (member);

      if (visitor.visit_union_member (member) == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_valuebox_cs::visit_structure - "
                             "visit_field failed\n"
                         ), -1);
        }
    }


  // Retrieve the disriminant type.
  be_type *bt;
  bt = be_type::narrow_from_decl (node->disc_type ());

  if (!bt)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_valuebox_ci::visit_union - "
                         "bad disciminant type\n"),
                        -1);
    }


  // Generate modifier and accessor for discriminant
  *os << "ACE_INLINE void " << be_nl
      << vb_node->name () << "::_d (" << bt->nested_type_name (node) << " val)"
      << be_nl
      << "{" << be_idt_nl
      << "this->_pd_value->_d (val);" << be_uidt_nl
      << "}" << be_nl << be_nl;

  *os << "ACE_INLINE " << bt->nested_type_name (node) << be_nl
      << vb_node->name () << "::_d (void) const" << be_nl
      << "{" << be_idt_nl
      << "return this->_pd_value->_d ();" << be_uidt_nl
      << "}" << be_nl << be_nl;


  // _tao_marshal_v method
  *os << "ACE_INLINE CORBA::Boolean " << be_nl
      << vb_node->name ()
      << "::_tao_marshal_v (TAO_OutputCDR & strm) const" << be_nl
      << "{" << be_idt_nl  
      << "return (strm << this->_pd_value.in ());" << be_uidt_nl 
      << "}" << be_nl << be_nl;

  return 0;
}



int
be_visitor_valuebox_ci::emit_for_predef_enum (be_type *node,
                                              const char * type_suffix,
                                              bool is_any,
                                              const char * marshal_arg)
{
  TAO_OutStream *os = this->ctx_->stream ();

  // Retrieve the node being visited by this be_visitor_valuebox_ci.
  be_decl * vb_node = this->ctx_->node ();
  
  *os << be_nl << be_nl << "// TAO_IDL - Generated from" << be_nl
      << "// " << __FILE__ << ":" << __LINE__ << be_nl << be_nl;

  this->emit_destructor ();

  if (is_any)
    {
      this->emit_default_constructor_alloc (node);
      this->emit_copy_constructor_alloc (node);
      this->emit_constructor_one_arg_alloc (node);
      this->emit_assignment_alloc (node);
      this->emit_accessor_modifier (node);
      this->emit_boxed_access (node, "*");
    }
  else
    {
      this->emit_default_constructor ();
      this->emit_copy_constructor ();
      this->emit_constructor_one_arg (node, type_suffix);
      this->emit_assignment (node, type_suffix);

      // Public accessor method
      *os << "ACE_INLINE " << node->full_name () << type_suffix << be_nl 
          << vb_node->name () << "::_value (void) const" << be_nl
          << "{" << be_idt_nl
          << "return this->_pd_value;" << be_uidt_nl
          << "}" << be_nl << be_nl;

      // Public modifier method
      *os << "ACE_INLINE void" << be_nl 
          << vb_node->name () << "::_value (" 
          << node->full_name ()
          << type_suffix << " val)" << be_nl
          << "{" << be_idt_nl
          << "this->_pd_value = val;" << be_uidt_nl
          << "}" << be_nl << be_nl;

      // Explicit conversion functions
      *os << "ACE_INLINE " << node->full_name () << type_suffix << be_nl 
          << vb_node->name () << "::_boxed_in (void) const" << be_nl
          << "{" << be_idt_nl
          << "return this->_pd_value;" << be_uidt_nl
          << "}" << be_nl << be_nl;

      *os << "ACE_INLINE " << node->full_name () << type_suffix << "&" << be_nl 
          << vb_node->name () << "::_boxed_inout (void)" << be_nl
          << "{" << be_idt_nl
          << "return this->_pd_value;" << be_uidt_nl
          << "}" << be_nl << be_nl;

      *os << "ACE_INLINE " << node->full_name () << type_suffix << "&" << be_nl 
          << vb_node->name () << "::_boxed_out (void)" << be_nl
          << "{" << be_idt_nl
          << "return this->_pd_value;" << be_uidt_nl
          << "}" << be_nl << be_nl;

    }

  // _tao_marshal_v method
  *os << "ACE_INLINE CORBA::Boolean " << be_nl
      << vb_node->name ()
      << "::_tao_marshal_v (TAO_OutputCDR & strm) const" << be_nl
      << "{" << be_idt_nl  
      << "return (strm << " << marshal_arg << ");" << be_uidt_nl 
      << "}" << be_nl << be_nl;

  return 0;
}

void
be_visitor_valuebox_ci::emit_default_constructor (void)
{
  TAO_OutStream *os = this->ctx_->stream ();

  // Retrieve the node being visited by this be_visitor_valuebox_ci.
  be_decl * vb_node = this->ctx_->node ();

  // Public default constructor
  *os << "ACE_INLINE" << be_nl;
  *os << vb_node->name () << "::" << vb_node->local_name ()
      << " (void)" << be_nl;
  *os << "{}" << be_nl << be_nl;
}

void
be_visitor_valuebox_ci::emit_default_constructor_alloc (be_decl *node)
{
  TAO_OutStream *os = this->ctx_->stream ();

  // Retrieve the node being visited by this be_visitor_valuebox_ci
  be_decl * vb_node = this->ctx_->node ();

  // Public default constructor
  *os << "ACE_INLINE " << be_nl 
      << vb_node->name () << "::" << vb_node->local_name () << " (void)"
      << be_nl << "{" << be_idt_nl
      << node->full_name () << "* p;" << be_nl
      << "ACE_NEW_THROW_EX (" << be_idt_nl
      << "p," << be_nl
      << node->full_name () << " ()," << be_nl
      << "CORBA::NO_MEMORY ()" << be_uidt_nl
      << ");" << be_nl
      << "this->_pd_value = p;" << be_uidt_nl
      << "}" << be_nl << be_nl;
}


void
be_visitor_valuebox_ci::emit_destructor (void)
{
  TAO_OutStream *os = this->ctx_->stream ();

  // Retrieve the node being visited by this be_visitor_valuebox_ci.
  be_decl * vb_node = this->ctx_->node ();

  // Protected destructor
  *os << "ACE_INLINE " << be_nl
      << vb_node->name () << "::~" << vb_node->local_name () << " (void)"
      << be_nl << "{}" << be_nl << be_nl;
}


void
be_visitor_valuebox_ci::emit_constructor_one_arg (be_decl *node,
                                                  const char * type_suffix)
{
  TAO_OutStream *os = this->ctx_->stream ();

  // Retrieve the node being visited by this be_visitor_valuebox_ci.
  be_decl * vb_node = this->ctx_->node ();

  // Public constructor with one argument of underlying type
  *os << "ACE_INLINE " << be_nl
      << vb_node->name () << "::" << vb_node->local_name () << " ("
      << node->full_name () << type_suffix << " val)" << be_nl
      << "{" << be_idt_nl
      << "this->_pd_value = val;" << be_uidt_nl
      << "}" << be_nl << be_nl;
}

void
be_visitor_valuebox_ci::emit_constructor_one_arg_alloc (be_decl *node)
{
  TAO_OutStream *os = this->ctx_->stream ();

  // Retrieve the node being visited by this be_visitor_valuebox_ci.
  be_decl * vb_node = this->ctx_->node ();

  // Public constructor with single argument of type const T&
  *os << "ACE_INLINE " << be_nl
      << vb_node->name () << "::" << vb_node->local_name ()
      << " (const " << node->full_name () << "& value)" << be_nl
      << "{" << be_idt_nl
      << node->full_name () << "* p;" << be_nl
      << "ACE_NEW_THROW_EX (" << be_idt_nl
      << "p," << be_nl
      << node->full_name () << " (value)," << be_nl
      << "CORBA::NO_MEMORY ()" << be_uidt_nl
      << ");" << be_nl 
      << "this->_pd_value = p;" << be_uidt_nl
      << "}" << be_nl << be_nl;
}

void
be_visitor_valuebox_ci::emit_copy_constructor (void)
{
  TAO_OutStream *os = this->ctx_->stream ();

  // Retrieve the node being visited by this be_visitor_valuebox_ci.
  be_decl * vb_node = this->ctx_->node ();

  // Public Copy constructor
  *os << "ACE_INLINE " << be_nl
      << vb_node->name () << "::" << vb_node->local_name ()
      << " (const " << vb_node->full_name () << "& val)" << be_nl
      << "{" << be_idt_nl
      << "this->_pd_value = val._pd_value;" << be_uidt_nl
      << "}" << be_nl << be_nl;
}

void
be_visitor_valuebox_ci::emit_copy_constructor_alloc (be_decl *node)
{
  TAO_OutStream *os = this->ctx_->stream ();

  // Retrieve the node being visited by this be_visitor_valuebox_ci.
  be_decl * vb_node = this->ctx_->node ();

  // Public copy constructor
  *os << "ACE_INLINE " << be_nl
      << vb_node->name () << "::" << vb_node->local_name () << " (const "
      << vb_node->full_name () << "& value)" << be_nl
      << "{" << be_idt_nl
      << node->full_name () << "* p;" << be_nl
      << "ACE_NEW_THROW_EX (" << be_idt_nl
      << "p," << be_nl
      << node->full_name () << " (value._pd_value.in ())," << be_nl
      << "CORBA::NO_MEMORY ()" << be_uidt_nl
      << ");" << be_nl 
      << "this->_pd_value = p;" << be_uidt_nl
      << "}" << be_nl << be_nl;
}


void
be_visitor_valuebox_ci::emit_assignment (be_decl *node,
                                         const char * type_suffix)
{
  TAO_OutStream *os = this->ctx_->stream ();

  // Retrieve the node being visited by this be_visitor_valuebox_ci.
  be_decl * vb_node = this->ctx_->node ();

  // Public assignment operator with one argument of underlying type
  *os << "ACE_INLINE " << vb_node->name () << " &" << be_nl
      << vb_node->name () << "::operator= ("
      << node->full_name () << type_suffix << " val)" << be_nl
      << "{" << be_idt_nl
      << "this->_pd_value = val;" << be_nl
      << "return *this;" << be_uidt_nl
      << "}" << be_nl << be_nl;
}

void
be_visitor_valuebox_ci::emit_assignment_alloc (be_decl *node)
{
  TAO_OutStream *os = this->ctx_->stream ();

  // Retrieve the node being visited by this be_visitor_valuebox_ci.
  be_decl * vb_node = this->ctx_->node ();

  // Public assignment operator with one argument of type const T&
  *os << "ACE_INLINE " << vb_node->name () << " &" << be_nl
      << vb_node->name () << "::operator= (const "
      << node->full_name () << "& value)" << be_nl
      << "{" << be_idt_nl
      << node->full_name () << "* p;" << be_nl
      << "ACE_NEW_THROW_EX (" << be_idt_nl
      << "p," << be_nl
      << node->full_name () << " (value)," << be_nl
      << "CORBA::NO_MEMORY ()" << be_uidt_nl
      << ");" << be_nl << be_nl
      << "this->_pd_value = p;" << be_nl
      << "return *this;" << be_uidt_nl
      << "}" << be_nl << be_nl;
}


void
be_visitor_valuebox_ci::emit_accessor_modifier (be_decl *node)
{
  TAO_OutStream *os = this->ctx_->stream ();

  // Retrieve the node being visited by this be_visitor_valuebox_ci.
  be_decl * vb_node = this->ctx_->node ();

  // Public accessor method (const)
  *os << "ACE_INLINE const " << node->full_name () << " &" << be_nl 
      << vb_node->name () << "::_value (void) const" << be_nl
      << "{" << be_idt_nl
      << "return this->_pd_value.in ();" << be_uidt_nl
      << "}" << be_nl << be_nl;

  // Public accessor method
  *os << "ACE_INLINE " << node->full_name () << " &" << be_nl 
      << vb_node->name () << "::_value (void)" << be_nl
      << "{" << be_idt_nl
      << "return this->_pd_value.inout ();" << be_uidt_nl
      << "}" << be_nl << be_nl;

  // Public modifier method
  *os << "ACE_INLINE void" << be_nl 
      << vb_node->name () << "::_value (const " 
      << node->full_name () << "& value)" << be_nl
      << "{" << be_idt_nl
      << node->full_name () << "* p;" << be_nl
      << "ACE_NEW_THROW_EX (" << be_idt_nl
      << "p," << be_nl
      << node->full_name () << " (value)," << be_nl
      << "CORBA::NO_MEMORY ()" << be_uidt_nl
      << ");" << be_nl 
      << "this->_pd_value = p;" << be_uidt_nl
      << "}" << be_nl << be_nl;
}

void
be_visitor_valuebox_ci::emit_boxed_access (be_decl *node,
                                           const char *out_ref_modifier)
{
  TAO_OutStream *os = this->ctx_->stream ();

  // Retrieve the node being visited by this be_visitor_valuebox_ci.
  be_decl * vb_node = this->ctx_->node ();

  // Access to the boxed value for method signatures
  *os << "ACE_INLINE const " << node->full_name () << " &" << be_nl 
      << vb_node->name () << "::_boxed_in (void) const" << be_nl
      << "{" << be_idt_nl
      << "return this->_pd_value.in ();" << be_uidt_nl
      << "}" << be_nl << be_nl;

  *os << "ACE_INLINE " << node->full_name () << "&" << be_nl 
      << vb_node->name () << "::_boxed_inout (void)" << be_nl
      << "{" << be_idt_nl
      << "return this->_pd_value.inout ();" << be_uidt_nl
      << "}" << be_nl << be_nl;

  *os << "ACE_INLINE " << node->full_name ()
      << out_ref_modifier << "&" << be_nl 
      << vb_node->name () << "::_boxed_out (void)" << be_nl
      << "{" << be_idt_nl
      << "return this->_pd_value.out ();" << be_uidt_nl
      << "}" << be_nl << be_nl;
}
