Symbol dispatch_class::CheckExprType() {
    bool error = false;

    Symbol expr_type = expr->CheckExprType();

    if (expr_type == SELF_TYPE) {
        log << "Dispatch: class = " << SELF_TYPE << "_" << curr_class->GetName() << std::endl;
    } else {
        log << "Dispatch: class = " << expr_type << std::endl;
    }

    // Find the method along the inheritance path.
    // We want the definition in a subclass.
    std::list<Symbol> path = classtable->GetInheritancePath(expr_type);
    method_class* method = NULL;
    for (std::list<Symbol>::iterator iter = path.begin(); iter != path.end(); ++iter) {
        log << "Looking for method in class " << *iter << std::endl;
        if ((method = methodtables[*iter].lookup(name)) != NULL) {
            break;
        }
    }

    if (method == NULL) {
        error = true;
        classtable->semant_error(curr_class) << "Error! Cannot find method '" << name << "'" << std::endl;
    }

    // Check the params.
    for (int i = actual->first(); actual->more(i); i = actual->next(i)) {
        Symbol actual_type = actual->nth(i)->CheckExprType();
        if (method != NULL) {
            Symbol formal_type = method->GetFormals()->nth(i)->GetType();
            if (classtable->CheckInheritance(formal_type, actual_type) == false) {
                classtable->semant_error(curr_class) << "Error! Actual type " << actual_type << " doesn't suit formal type " << formal_type << std::endl;
                error = true;
            }
        }
    }

    if (error) {
        type = Object;
    } else {
        type = method->GetType();
        if (type == SELF_TYPE) {
            type = expr_type;
        }
    }

    return type;
}