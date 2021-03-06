#include "main.h"

void Test_Operator_Binary()
{
	Core::ValueModel<double> v1(1);
	Core::ValueModel<double> v2;
	v2.SetValue(2);
	assert(1 == v1.Evaluate());
	assert(2 == v2.Evaluate());

	Fuzzy::AndMin<double> andMin;
	Core::ValueModel<double> andMinValue = andMin.Evaluate(&v1,&v2);
	assert(andMinValue.Evaluate() == 1);

	Fuzzy::AndMult<double> andMult;
	Core::ValueModel<double> andMultValue = andMult.Evaluate(&v1,&v2);
	assert(andMultValue.Evaluate() == 2);

	Fuzzy::AggMax<double> aggMax;
	Core::ValueModel<double> aggMaxValue = aggMax.Evaluate(&v1,&v2);
	assert(aggMaxValue.Evaluate() == 2);

	Fuzzy::AggPlus<double> aggPlus;
	Core::ValueModel<double> aggPlusValue = aggPlus.Evaluate(&v1,&v2);
	assert(aggPlusValue.Evaluate() == 3);

	Fuzzy::OrMax<double> orMax;
	Core::ValueModel<double> orMaxValue = orMax.Evaluate(&v1,&v2);
	assert(orMaxValue.Evaluate() == 2);

	Fuzzy::OrPlus<double> orPlus;
	Core::ValueModel<double> orPlusValue = orPlus.Evaluate(&v1,&v2);
	assert(orPlusValue.Evaluate() == 1);

	Fuzzy::ThenMin<double> thenMin;
	Core::ValueModel<double> thenMinValue = thenMin.Evaluate(&v1,&v2);
	assert(thenMinValue.Evaluate() == 1);

	Fuzzy::ThenMult<double> thenMult;
	Core::ValueModel<double> thenMultValue = thenMult.Evaluate(&v1,&v2);
	assert(thenMultValue.Evaluate() == 2);

	Fuzzy::NotMinus<double> notMinus;
	Core::ValueModel<double> notMinusValue = notMinus.Evaluate(&v1);
	assert(notMinusValue.Evaluate() == -1);

	Core::BinaryExpressionModel<double> bin (&andMult, &v1, &v2);
	assert(bin.Evaluate() == 2);

}

void Test_Operator_Unary()
{
	Core::ValueModel<double> v1 ( 1 );
	Core::ValueModel<double> v2 ( 3 );
	Core::ValueModel<double> v3 ( 5 );
	Core::ValueModel<double> v4 ( 7 );
	assert(1 == v1.Evaluate());
	assert(3 == v2.Evaluate());
	assert(5 == v3.Evaluate());
	assert(7 == v4.Evaluate());

	Fuzzy::IsTriangle<double> isTriangle(0,5,10);
	Core::ValueModel<double> isTriangleValueMin = isTriangle.Evaluate(&v1);
	Core::ValueModel<double> isTriangleValueMax = isTriangle.Evaluate(&v4);
	assert(isTriangleValueMin.Evaluate() == 0.2);
	assert(isTriangleValueMax.Evaluate() == 0.6);

	Fuzzy::IsTrapeze<double> IsTrapeze(0,2,4,6);
	Core::ValueModel<double> IsTrapezeValueMin = IsTrapeze.Evaluate(&v1);
	Core::ValueModel<double> IsTrapezeValueMid = IsTrapeze.Evaluate(&v2);
	Core::ValueModel<double> IsTrapezeValueMax = IsTrapeze.Evaluate(&v3);
	Core::ValueModel<double> IsTrapezeValueOut = IsTrapeze.Evaluate(&v4);
	assert(IsTrapezeValueMin.Evaluate() == 0.5);
	assert(IsTrapezeValueMid.Evaluate() == 1);
	assert(IsTrapezeValueMax.Evaluate() == 0.5);
	assert(IsTrapezeValueOut.Evaluate() == 0);

	Fuzzy::IsTrapezeLeft<double> isTrapezeLeft(0,2,4);
	Core::ValueModel<double> isTrapezeLeftValueMid = isTrapezeLeft.Evaluate(&v1);
	Core::ValueModel<double> isTrapezeLeftValueMax = isTrapezeLeft.Evaluate(&v2);
	Core::ValueModel<double> isTrapezeLeftValueOut = isTrapezeLeft.Evaluate(&v3);
	assert(isTrapezeLeftValueMid.Evaluate() == 0.5);
	assert(isTrapezeLeftValueMax.Evaluate() == 1);
	assert(isTrapezeLeftValueOut.Evaluate() == 0);

	Fuzzy::IsTrapezeRight<double> isTrapezeRight(0,2,4);
	Core::ValueModel<double> isTrapezeRightValueMin = isTrapezeRight.Evaluate(&v1);
	Core::ValueModel<double> isTrapezeRightValueMid = isTrapezeRight.Evaluate(&v2);
	Core::ValueModel<double> isTrapezeRightValueOut = isTrapezeRight.Evaluate(&v3);
	assert(isTrapezeRightValueMin.Evaluate() == 1);
	assert(isTrapezeRightValueMid.Evaluate() == 0.5);
	assert(isTrapezeRightValueOut.Evaluate() == 0);

	Fuzzy::IsGaussian<double> isGaussian(1,1);
	Core::ValueModel<double> isGaussianValue = isGaussian.Evaluate(&v1);
	assert(isGaussianValue.Evaluate() == 1);

	Fuzzy::IsBell<double> isBell(1,1,1);
	Core::ValueModel<double> isBellValue = isBell.Evaluate(&v1);
	assert(isBellValue.Evaluate() == 1);

	Core::UnaryExpressionModel<double> una (&isTriangle, &v1);
	assert(una.Evaluate() == 0.2);
}

void Test_Factory()
{
	////membership function 
	//Fuzzy::IsGaussian<double> poor(1.5,0);
	//Fuzzy::IsGaussian<double> good(0.8,5);
	//Fuzzy::IsGaussian<double> excellent(3,10);

	Fuzzy::IsTriangle<double> poor(-5,0,5);
	Fuzzy::IsTriangle<double> good(0,5,10);
	Fuzzy::IsTriangle<double> excellent(5,10,15);

	Fuzzy::IsTriangle<double> cheap(0,5,10);
	Fuzzy::IsTriangle<double> average(10,15,20);
	Fuzzy::IsTriangle<double> generous(20,25,30);

	Fuzzy::IsTrapezeLeft<double> rancid(1.5,3.5,5.5);
	Fuzzy::IsTrapezeRight<double> delicious(6.5,7.5,8.5);


	//values
	Core::ValueModel<double> service (0);
	Core::ValueModel<double> food (0);
	Core::ValueModel<double> tips (0);

	Fuzzy::AndMult<double> andMult;
	Fuzzy::AggMax<double> aggMax;
	Fuzzy::OrPlus<double> orPlus;
	Fuzzy::ThenMin<double> thenMin;
	Fuzzy::NotMinus<double> notMinus;

	Fuzzy::CogDefuzz<double> defuzz (0,25,1);

	//Sugeno init
	Fuzzy::SugenoDefuzz<double> sugeno;
	std::vector<double> coef; coef.push_back(5);coef.push_back(1);
	Fuzzy::SugenoConclusion<double> conclusion (&coef);

	std::vector<const Core::Expression<double>* > SCservicefood;
	SCservicefood.push_back(&service);
	SCservicefood.push_back(&food);
	std::vector<const Core::Expression<double>* > SCservice;
	SCservice.push_back(&service);

	Fuzzy::SugenoThen<double> sugenoThen;

	Fuzzy::FuzzyFactory<double> f(&notMinus, &andMult, &orPlus, &thenMin, &aggMax, &defuzz, &sugeno, &conclusion);

	Core::Expression<double> *r = 
	f.NewAgg(
		f.NewAgg(
			f.NewThen(
				f.NewOr(
					f.NewIs(&service,&poor),
					f.NewIs(&food, &rancid)	
				),
				f.NewIs(&tips,&cheap)
			),
			f.NewThen(
				f.NewIs(&service,&good),
				f.NewIs(&tips,&average)
			)
		),
		f.NewThen(
			f.NewOr(
				f.NewIs(&service, &excellent),
				f.NewIs(&food, &delicious)
			),
			f.NewIs(&tips,&generous)
		)
	);

	//defuzzification
	Core::Expression<double> *system = f.NewDefuzz(r, &tips);

	std::vector<const Core::Expression<double>*> rules;

	rules.push_back(
		f.NewThen(
				f.NewOr(
					f.NewIs(&service, &poor),
					f.NewIs(&food, &rancid)
				),
				f.NewConclusion(&SCservicefood)
		)
	);

	rules.push_back(
		f.NewThen(
				f.NewIs(&service, &good),
				f.NewConclusion(&SCservice)
		)
	);

	rules.push_back(
		f.NewThen(
				f.NewOr(
					f.NewIs(&service, &excellent),
					f.NewIs(&food, &delicious)
				),
				f.NewConclusion(&SCservicefood)
		)
	);

	//defuzzification
	Core::Expression<double> *resu = f.NewSugeno(&rules);

	int choice = 1;
	double s;
	while(true)
	{
		if(choice == 0)
		{
			std::cout << "******[Sugeno]*****"<< std::endl;
			f.ChangeThen(&sugenoThen);
			std::cout << "service : ";
			std::cin >> s;
			service.SetValue(s);
			std::cout << "food : ";
			std::cin >> s;
			food.SetValue(s);
			std::cout << "tips -> " << resu->Evaluate() << std::endl;
		}
		else
		{
			std::cout << "******[Mamdani]*****" << std::endl;
			f.ChangeThen(&thenMin);
			cout << "service : ";
			cin >> s;
			service.SetValue(s);
			std::cout << "food : ";
			std::cin >> s;
			food.SetValue(s);
			cout << "tips -> " << system->Evaluate() << endl;
		}
		std::cout << "[0] Sugeno - [1] Mamdani";
		std::cin >> choice;
	}
}

int main()
{
	cout << "Starting Test...." << endl;
	cout << "Test Binary Operator" << endl;
	Test_Operator_Binary();
	cout << "Test Binary Operator check" << endl;
	cout << "Test Unary Operator" << endl;
	Test_Operator_Unary();
	cout << "Test Binary Operator check" << endl;
	Test_Factory();
	return 0;
}