const axios = require('axios');

const testApi = async () => {
    try {
        let response;

        // Test root endpoint
        response = await axios.get('http://localhost:3000/');
        console.log('Root endpoint:', response.status, response.data);

        // Test items endpoint
        response = await axios.get('http://localhost:3000/items/1');
        console.log('Items endpoint:', response.status, response.data);

        // Test rate limiting
        for (let i = 0; i < 6; i++) {
            try {
                response = await axios.get('http://localhost:3000/');
                console.log(`Request ${i + 1}:`, response.status, response.data);
            } catch (error) {
                console.log(`Request ${i + 1}:`, error.response.status, error.response.data);
            }
        }
    } catch (error) {
        console.error(error);
    }
};

testApi();
