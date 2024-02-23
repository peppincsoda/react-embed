const path = require('path');
const CopyPlugin = require("copy-webpack-plugin");

module.exports = {
  entry: './src/index.js',
  mode: 'development',

  module: {
    rules: [
      {
        test: /\.jsx?$/,
        use: 'ts-loader',
        exclude: /node_modules/,
        use: {
          loader: "babel-loader",
          options: {
            cacheDirectory: true,
            cacheCompression: false,
            envName: "development"
          }
        }
      }
    ],
  },

  resolve: {
    extensions: ['.js'],
  },
  output: {
    path: path.resolve(__dirname, 'dist'),
  },

  plugins: [
    new CopyPlugin({
      patterns: [
        { from: "src/index.html", to: "index.html" },
        { from: "src/style.css", to: "style.css" },
      ],
    }),
  ],

  externals: {
    react: 'React',
    'react-dom': 'ReactDOM',
  },
};
