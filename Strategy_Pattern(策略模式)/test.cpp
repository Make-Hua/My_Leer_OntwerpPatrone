enum TaxBase {
	CN_Tax,
	US_Tax,
	DE_Tax,
	FR_Tax
};

 // 当我们遇到以下这种类似的情况时，我们可以考虑策略模式

class SalesOrder{
    TaxBase tax;
public:
    double CalculateTax(){
        //...
        
        if (tax == CN_Tax){

        }
        else if (tax == US_Tax){
            //
        }
        else if (tax == DE_Tax){
            //
        }
		else if (tax == FR_Tax){
			//
		}

     }
    
};
