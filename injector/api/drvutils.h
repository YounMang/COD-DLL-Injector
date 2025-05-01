#pragma once

void start_driver()
{
	driver().handle_driver();

	if (!driver().is_loaded())
	{
		cout << xor_a("\n Loading driver...") << endl;
		mmap_driver();
	}

	driver().handle_driver();
	driver().is_loaded() ? cout << xor_a("\n [+] Successfully loaded Driver.") << endl : cout << xor_a("\n [-] An Error occured: Driver Failed to Load.") << endl;
}

